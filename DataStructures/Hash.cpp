// Hash.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <memory>
#include <iostream>
#include <functional>
#include <algorithm>
#include <cassert>
#define HMAX 6013

using namespace std;

template < typename T >

class List {
private:

	struct __list {
		T _info;
		unique_ptr < __list > next;
	};

	unique_ptr < __list > __head;

	__list *anterior;
	size_t __size;

	void __insert(const T &val) {
		anterior->next = make_unique < __list >();
		anterior->next->_info = val;
		anterior = anterior->next.get();
	}

	void __EmplaceHead(const T & val) {
		++__size;
		auto q = make_unique < __list >();
		q->_info = __head->_info;
		q->next = move(__head->next);
		__head->_info = val;
		__head->next = move(q);
	}

public:


	class iterator {
	private:

		__list *__ptr;

	public:

		iterator(__list *ptr) :__ptr(ptr) {};

		T operator *() {
			return __ptr->_info;
		}

		iterator operator ++ () {
			__ptr = __ptr->next.get();
			return *this;
		}

		iterator operator ++ (int junk) {
			auto ptr = *this;
			this->__ptr = __ptr->next.get();
			return ptr;
		}

		friend bool operator != (iterator & __it, __list * __ptr) {
			return __it.__ptr != __ptr;
		}

		__list* operator ->() {
			return __ptr;
		}

	};

	List() {
		__size = 0;
	}

	void Insert(const T & val) {
		if (!__size) {
			__head = make_unique < __list >();
			anterior = __head.get();
			__head->_info = val;
		}
		else __insert(val);
		++__size;
	}

	void Emplace(const T & val, size_t Poz) {
		///empace the value of the elemement indicated by Poz with val and automaticaly extend  the list
		if (Poz <= 0 || Poz >= __size)return;
		if (Poz == 1) {
			__EmplaceHead(val);
			return;
		}
		auto str = __head.get();
		--Poz;
		while (Poz-- > 1)str = str->next.get();
		auto __new = make_unique < __list >();
		__new->_info = val;
		__new->next = move(str->next);
		str->next = move(__new);
		++__size;
	}


	void Erase(const T&val) {

		///delete's all ocurences of val in list

		if (!__head)return;
		while (__head && __head->_info == val)__head = move(__head->next), --__size;

		if (!__head) return;

		auto __ptr = __head->next.get(), __ant = __head.get();

		while (__ptr) {
			if (__ptr->_info == val) {
				if (__ptr == anterior) anterior = __ant;//daca stergem ultimul emelent atunci nu vom mai sti unde sa inseram deci ultimul element(ala dupa care vom ins va fi cel dinaintea sa)
				--__size;
				__ant->next = move(__ptr->next);
				__ptr = __ant->next.get();
				continue;
			}
			__ant = __ptr;
			__ptr = __ptr->next.get();
		}

	}

	inline size_t Size() {
		return __size;
	}

	void Erase(size_t _spoz, size_t _epoz) {

		if (!__size)return;

		_epoz = min(_epoz, Size());
		if (_spoz > _epoz || _spoz <= 0 || _epoz <= 0)return;
		auto st = __head.get();

		size_t __i = 1;

		while (__i < _spoz - 1) st = st->next.get(), ++__i;

		auto dr = st->next.get();
		
		while (__i < _epoz - 1)dr = dr->next.get(), ++__i;

		if (_spoz == 1) {
			if(dr)__head = move(dr->next);
			else
				__head.reset(nullptr);
			if (_epoz == 1)anterior = nullptr;
			else 
				if (dr == anterior)anterior = __head.get();
		}
		else {
			if (dr == anterior)anterior = st;
			st->next = move(dr->next);
		}

		__size -= (_epoz - _spoz + 1);
		
	}

	template < typename T >
	void ForEach(const function < T > &fct) {
		auto __ptr = __head.get();
		while (__ptr) {
			fct(__ptr->_info);
			__ptr = __ptr->next.get();
		}
	}

	__list * begin() {
		return __head.get();
	}

	__list * end() {
		if (anterior == nullptr)return nullptr;
		return anterior->next.get();
	}

};

template <typename T>

class Hash {
private:
	struct __hash {
		T info;
		List < T > __lst;
	}H[HMAX];

public:

	void insert(const T & val) {
		size_t hKey = val % HMAX;
		H[hKey].__lst.Insert(val);
	}

	inline bool find(const T & val) {
		size_t hKey = val % HMAX;
		for (List < T > ::iterator it = H[hKey].__lst.begin(); it != H[hKey].__lst.end(); ++it) if (*it == val)return true;
		return false;
	}

	void Erase(const int &val) {
		size_t hKey = val % HMAX, index = 1;
		for (List < T > ::iterator it = H[hKey].__lst.begin(); it != H[hKey].__lst.end(); ++it,++index)
			if (*it == val) {
				H[hKey].__lst.Erase(index, index);
				return;
			}
	}
};


int main()
{
	Hash <int> H;
	List <int>L;
	for (int i = 1; i <= 201; ++i) {
		auto val = i + rand() % 17;
		H.insert(val);
		L.Insert(val);
	}
	for (List <int>::iterator it = L.begin(); it != L.end(); ++it)assert(H.find(*it));
	for (List <int>::iterator it = L.begin(); it != L.end(); ++it)H.Erase(*it);
	for (List <int>::iterator it = L.begin(); it != L.end(); ++it)assert(!H.find(*it));
    return 0;
}

