// List(lodv).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "vector.h"
#include <stdexcept>
#include <iostream>
#include <cassert>
#include <string>

class index_out_of_range : public std::exception {
private:
	std::string mesage;

public:

	explicit index_out_of_range(const char *msg) : mesage(msg) {}

	const char * what() const { return mesage.c_str(); }
};

template <typename T, typename U>
struct pair {
	T first;
	U second;
	pair(){}
	pair(const T &__first, const T &__second) : first(__first), second(__second) {}
};

template <typename T>
class list {
public:

	class iterator;
	typedef typename list<T>::iterator Iterator;

private:
	const static int NMAX = 100;

	struct __listEl {
		vector < pair <T, int > >__store;
		vector < int > deleted;
		int startPoint, endPoint;
		__listEl() {
			__store.Resize(NMAX + 1);
			startPoint = endPoint = -1;
		}
	};

	__listEl *__MyContainer;

	int __size;

	inline int getAFreePozition() const;

	inline void __adaugaRezidual(int pozition, const T &val);

	inline void __adaugaNormal(int pozition, const T &val);

	inline void __adaugaInceputR(int pozition, const T &val);

	inline void __adaugaInceputN(int pozition, const T &val);

public:

	list() : __MyContainer{ new __listEl() }, __size{ 0 }{}

	inline int size() const { return __size; }

	void push_back(const T &val);

	void erase(const Iterator &val);

	void insert(const Iterator &__it, const T &val);

	void clear();

	inline bool empty() { return !__size; }

	void push_front(const T &val);

	inline iterator begin();

	inline iterator end();

	~list() { delete __MyContainer; }
};

template <typename T>class list<T>::iterator {
private:

	__listEl *Pointer;

	int startP, endP;

public:
	
	iterator(__listEl *ptr) :startP{ ptr->startPoint }, endP{ (ptr->__store.Size() ? ptr->__store[ptr->endPoint].second : -1) } { Pointer = ptr; }

	inline bool operator != (const iterator &it) const {
		return startP != it.endP;
	}

	iterator &operator ++ () {
		if (startP == -1)throw index_out_of_range("Index out of range!!!");
		startP = Pointer->__store[startP].second;
		return *this;
	}

	iterator &operator ++(int junk) {
		if (startP == -1)throw index_out_of_range("Index out of range!!!");
		auto p = *this;
		this->startP = Pointer->__store[startP].second;
		return p;
	}

	iterator &operator + (int value) {
		while (value-- > 0 && startP > -1)startP = Pointer->__store[startP].second;
		if (value && startP == -1)throw index_out_of_range("Out of range !!!");
		return *this;
	}

	T operator *() {
		return Pointer->__store[startP].first;
	}

	friend list<T>;

};

template <typename T> typename list<T>::iterator list<T>::begin() {
	return iterator(__MyContainer);
}

template <typename T> typename list<T>::iterator list<T>::end() {
	return iterator(__MyContainer);
}

template <typename T>int list<T>::getAFreePozition() const {

	int poz = __MyContainer->__store.Size();

	if (__MyContainer->deleted.Size()) poz = __MyContainer->deleted.back();

	return poz;
}

template <typename T>void list<T>::push_back(const T&val) {
	int __pozInser = getAFreePozition();

	if (__MyContainer->deleted.Size()) __adaugaRezidual(__pozInser, val);

	else
		__adaugaNormal(__pozInser, val);
	++__size;
}

template <typename T>void list<T>::__adaugaRezidual(int __pozition, const T &value) {

	__MyContainer->deleted.pop_back();

	if (__MyContainer->startPoint == -1) {
		__adaugaInceputR(__pozition, value);
		return;
	}

	__MyContainer->__store[__pozition] = { value,-1 };
	__MyContainer->__store[__MyContainer->endPoint].second = __pozition;
	__MyContainer->endPoint = __pozition;

}

template <typename T>void list<T>::__adaugaNormal(int __pozition, const T &value) {

	if (__MyContainer->startPoint == -1) {
		__adaugaInceputN(__pozition, value);
		return;
	}
	
	__MyContainer->__store[__MyContainer->endPoint].second = __MyContainer->__store.Size();
	__MyContainer->__store.push_back({ value,-1 });
	__MyContainer->endPoint = __MyContainer->__store.Size() - 1;

}

template<typename T> void list<T>::__adaugaInceputR(int __pozition, const T &value) {
	__MyContainer->startPoint = __MyContainer->endPoint = __pozition;
	__MyContainer->__store[__pozition] = { value , -1 };
}

template <typename T> void list<T>::__adaugaInceputN(int __pozition, const T&value) {
	__MyContainer->startPoint = __MyContainer->endPoint = __pozition;
	__MyContainer->__store.push_back({ value,-1 });
}

template <typename T> void list<T>::erase(const Iterator &it) {
	auto __delPosition = it.startP;

	if (it.startP == -1)throw index_out_of_range("Out of range!!!");

	__MyContainer->deleted.push_back(__delPosition);

	if (__delPosition == __MyContainer->startPoint) {
		auto __next = __MyContainer->__store[__MyContainer->startPoint].second;
		__MyContainer->__store[__MyContainer->startPoint].second = -1;
		__MyContainer->startPoint = __next;
		--__size;
		return;
	}

	--__size;

	int poz = __MyContainer->startPoint;

	while (__MyContainer->__store[poz].second != __delPosition)poz = __MyContainer->__store[poz].second;

	__MyContainer->__store[poz].second = __MyContainer->__store[__delPosition].second;

	__MyContainer->__store[__delPosition].second = -1;

	if (__delPosition == __MyContainer->endPoint)__MyContainer->endPoint = poz;
}

template <typename T>void list<T>::clear() {
	list<T>::iterator it = begin();
	while (it != end()) {
		erase(it);
		it = begin();
	}
}

template <typename T> void list<T>::push_front(const T &value) {

	if (__MyContainer->startPoint == -1) {
		push_back(value);
		return;
	}

	++__size;

	auto poz = getAFreePozition();

	if (__MyContainer->deleted.Size()) {
		__MyContainer->deleted.pop_back();
		__MyContainer->__store[poz] = { value,__MyContainer->startPoint };
		__MyContainer->startPoint = poz;
		return;
	}

	__MyContainer->__store.push_back({ value,__MyContainer->startPoint });
	__MyContainer->startPoint = poz;

}

template <typename T> void list<T>::insert(const Iterator &__it, const T &val) {

	if (__it.startP == __MyContainer->startPoint) {
		push_front(val);
		return;
	}
	
	if (__it.startP == __MyContainer->endPoint) {
		push_back(val);
		return;
	}

	++__size;

	auto poz = __MyContainer->startPoint;
	while (__MyContainer->__store[poz].second != __it.startP) poz = __MyContainer->__store[poz].second;

	auto __pozInserare = getAFreePozition();

	if (__MyContainer->deleted.Size()) {
		__MyContainer->deleted.pop_back();
		__MyContainer->__store[__pozInserare] = { val,__it.startP };
		__MyContainer->__store[poz].second = __pozInserare;
		return;
	}

	__MyContainer->__store.push_back({ val,__it.startP });
	__MyContainer->__store[poz].second = __pozInserare;

}

int main(){
	list<int>L;
	
	list<int>::iterator it = L.begin();
	std::cout << (it != L.end());
	try {
		++it;
		assert(false);
	}
	catch (index_out_of_range &e) {
		assert(true);
	}
	

	L.push_back(112);
	L.push_back(545);
	L.push_back(4545);
	
	L.erase(L.begin());
	
	L.push_back(4564);
	L.erase(L.begin() + 2);
	L.push_back(1545);
	for (int i = 1; i <= 14; ++i)L.push_back(i);
	L.clear();
	for (int i = 1; i <= 14; ++i)L.push_back(i);
	for (int i = 1; i <= 14; ++i)L.push_front(i);
	L.insert(L.begin(), 454);
	L.insert(L.begin() + 5, 45545);
	L.push_back(4655);
	L.push_front(-14);
	std::cout << '\n' << L.size() << '\n';
	L.clear();
	assert(L.empty() == true);
	std::cout << std::boolalpha << L.empty() << '\n';
	L.insert(L.begin(), 1);
	L.push_back(454);
	L.push_front(-1);
	for (auto v : L)std::cout << v << ' ';
	std::cout << '\n';
    return 0;
}

