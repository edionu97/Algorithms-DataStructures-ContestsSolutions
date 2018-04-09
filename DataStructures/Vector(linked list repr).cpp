// Class cheatie.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cassert>

template <typename T > struct Nod {
	T info;
	Nod * next;
	Nod(const T &val) : info {val} , next{nullptr}{}
};

template <typename T > class vector {
public:
	class iterator;
	typedef class vector <T> ::iterator Iterator;

private:

	Nod <T> *prim, *ultim;
	int __size;

	void __addInFata(const T &val);

	void __addInSpate(const T &val);

	void __stergeInceput();

	void __stergeSfarsit();


public:

	vector(const vector <T> &ref)  {
		prim = ultim = nullptr;
		auto p = ref.prim;
		while (p != nullptr) {
			push_back(p->info);
			p = p->next;
		}
	}

	vector() : prim{ nullptr }, ultim{ nullptr } { __size = 0; }

	void push_back(const T &val);
	
	void pop_back();

	void insert(const Iterator &it,const T &val);

	void erase(Iterator &it);

	inline bool empty() const { return __size == 0; };

	T & back() ;

	size_t size() const;

	T& operator [] (int index);
	
	inline iterator begin();

	inline iterator end();

	~vector();
};



template < typename T> class vector <T> ::iterator {
private:
	vector <T> &ref;

	Nod <T> *__prim,*__end;

public:

	iterator(vector <T> &rf) :ref{ rf } { __prim = rf.prim; __end = (rf.ultim == nullptr) ? nullptr : rf.ultim->next; }
	
	iterator(iterator &&ref) : ref{ ref.ref } { __prim = ref.__prim; __end = ref.__end;}

	iterator& operator ++() {
		__prim = __prim->next;
		return *this;
	}

	iterator& operator ++(int) {
		auto it = *this;
		__prim = __prim->next;
		return it;
	}

	T& operator * () {
		return __prim->info;
	}

	Nod<T>* operator -> () {
		return __prim;
	}

	Iterator& operator + (int i) {

		while (--i > 0 && __prim)__prim = __prim->next;
		return *this;
	}

	friend bool operator != (const iterator &it1, const iterator &it2) {
		return it1.__prim != it2.__end;
	}

	friend bool operator != (const iterator &it1, const Nod<T> *ptr) {
		return it1.__prim != ptr;
	}

	friend bool operator == (const iterator &it, const Nod<T> *ptr) {
		return !(it != ptr);
	}

	friend vector<T>;
};

template<typename T> typename vector<T>::iterator vector<T>::begin() {
	return iterator(*this);
}

template<typename T> typename vector<T>::iterator vector<T>::end() {
	return iterator(*this);
}


template <typename T> void vector <T> ::push_back(const T &val) {
	++__size;
	if (prim == nullptr) {
		__addInFata(val);
		return;
	}
	__addInSpate(val);
}

template <typename T > void vector <T>::__addInFata(const T &val) {

	auto __aux = new Nod<T>(val);
	__aux->next = prim;

	if (prim == nullptr) {
		prim = ultim = __aux;
		return;
	}

	prim = __aux;
}

template <typename T> void vector <T> ::__addInSpate(const T &val) {
	auto __aux = new Nod<T>(val);
	ultim->next = __aux;
	ultim = __aux;
}


template <typename T> vector<T>::~vector() {
	while (prim != nullptr) {
		auto q = prim->next;
		delete prim;
		prim = q;
	}
}

template <typename T> void vector <T> ::pop_back() {
	if (prim == nullptr)return;

	if (__size == 1) {
		delete prim;
		prim = ultim = nullptr;
		--__size;
		return;
	}

	--__size;
	
	vector<T>::iterator it=begin();
	for (; it->next != ultim; ++it);

	delete ultim;
	it->next = nullptr;
	ultim = it.__prim;
}

template <typename T> T& vector <T>::back() {
	auto it = begin();
	for (; it != ultim; ++it);
	return *it;
}

template <typename T>  void vector<T>::insert(const Iterator &it, const T &val) {

	if (it == prim) {
		__addInFata(val);
		++__size;
		return;
	}

	auto __it = begin();
	
	++__size;

	for (; __it->next != it.__prim; ++__it);

	auto __aux = new Nod<T>(val);

	__aux->next = it.__prim;

	__it->next = __aux;

}

template <typename T> void vector<T>::erase(Iterator &it) {

	if (it == prim) {
		__stergeInceput();
		--__size;
		return;
	}

	if (it == ultim) {
		__stergeSfarsit();
		--__size;
		return;
	}

	auto __it = begin();

	for (; __it->next != it.__prim; ++__it);

	__it->next = it->next;

	delete it.__prim;

}

template<typename T> void vector<T>::__stergeInceput() {
	auto aux = prim;
	prim = prim->next;
	if (__size == 1)ultim = nullptr;
	delete aux;
}

template <typename T> void vector <T> ::__stergeSfarsit() {
	auto it = begin();
	for (; it->next != ultim; ++it);
	delete ultim;
	it->next = nullptr;
	ultim = it.__prim;
}

template <typename T> size_t vector<T>::size() const {
	return __size;
}

template <typename T> T & vector <T> ::operator [](int index) {
	auto it = begin();
	while (--index > 0 && it != end())++it;
	return *it;
}



int main(){
	vector<int>L;

	L.push_back(454);
	L.push_back(45);
	L.push_back(144);
	L.push_back(10);

	L.pop_back();
	
	L.insert(L.begin(), 4);

	for (int i = 1; i <= 4; ++i)L.erase(L.begin());

	for (auto v : L) std::cout << v << ' ';

	L.push_back(454);
	for (auto v : L) std::cout << v << ' ';
	std::cout << '\n';
	std::cout << L.size() << std::endl;

	L[1] = 10;

	for (auto v : L) std::cout << v << ' ';

	for (int i = 1; i <= 100; ++i)L.push_back(i);

	
	std::cout << "\n";

	for (auto v : L) std::cout << v << ' ';

	std::cout << std::endl;

	while (!L.empty()) L.erase(L.begin());
	
	assert(! L.size() );

	vector < std::string >V4;
	V4.push_back("ana");
	V4.push_back("are");
	V4.push_back("mere");
	
	using namespace std;

	cout << '\n';
	for (auto v : V4)cout << v << ' ';
	cout << '\n';

	
	

	vector < vector < int > > v;

	vector <int> V;
	V.push_back(1);
	V.push_back(2);
	V.push_back(3);

	v.push_back(V);

	vector <int >V3;
	V3.push_back(1);
	V3.push_back(5);

	v.push_back(V3);

	std::cout << v[1][2] << ' ';
	cout << '\n';

	for (auto& i : v) {
		for (auto q : i)std::cout << q << ' ';
		std::cout << '\n';
	}

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    return 0;
}

