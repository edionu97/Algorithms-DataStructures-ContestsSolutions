// Hash(open adressing).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <utility>
#include <iostream>
#include <bitset>
using namespace std;

template < typename T,typename H > class hashTable {
public:
	class iterator;

private:

	const static int dim = 66013;
	vector < pair < T, int > > __table;

	H __hasher;

	bitset < dim > isNotfree;

	int findFirstFree() const {

		for (int i = 0; i < dim; ++i)
			if (!isNotfree[i])return i;

		return -1;
	}

	int __size = 0;

	void __insertIfNotEmpty(int key, T&& elem) {
		int dad;

		while (key >= 0) {
			dad = key; key = __table[key].second;
		}

		int free = findFirstFree();

		__table[dad].second = free;

		__table[free].first = move(elem);

		isNotfree[free] = true;
	}

	int __findDad(int curent) {
		for (int i = 0; i < dim; ++i)
			if (__table[i].second == curent)return i;
		return -1;
	}

	void __deleteIfMoreThanOne(int key,int iDad,int dad,const iterator& it) {

		int repeta;

		do {
			repeta = false;
			int i;

			for (i = __table[key].second; i >= 0; iDad = i, i = __table[i].second) {

				if (__hasher(__table[i].first) != key)  continue;

				repeta = true;

				int replace = (dad >= 0 ? __table[dad].second : it.curent);

				__table[replace].first = move(__table[i].first);

				key = i, dad = iDad;

				break;
			}

			if (i == -1) {//pot sterge
				__table[dad].second = __table[key].second;
				--__size;
				__table[key].second = -1, isNotfree[key] = false;
			}

		} while (repeta);

	}

public:

	hashTable() {
		__table.resize(dim, { T{},-1 });
	}

	void insert(T&& elem) {

		int key = __hasher(elem);
		if (key < 0)return;
		++__size;

		if (!isNotfree[key]) {
			__table[key].first = move(elem); isNotfree[key] = true;
			return;
		}

		__insertIfNotEmpty(key, move(elem));
	}

	iterator find(const T& elem) {

		int key = __hasher(elem);

		while (key >= 0 && __table[key].first != elem)key = __table[key].second;

		return iterator{ key >= 0 ? key : dim,*this };
	}

	void erase(const iterator& it) {

		if (!(it != end()))return;

		int dad = __findDad(it.curent),key = it.curent;

		if (__table[key].second == -1 && dad == -1) {
			isNotfree[key] = false, --__size;
			return;
		}

		__deleteIfMoreThanOne(key, dad,dad,it);
	}


	int size() const {
		return __size;
	}

	iterator begin();

	iterator end();
};


template < typename T, typename U > class hashTable < T, U >::iterator {
private:
	int curent;
	hashTable <T, U>& ref;

	void __repositionateCurent(){
		++curent;
		while (curent < ref.dim && !ref.isNotfree[curent])++curent;
	}

public:

	iterator(int start, hashTable<T, U>& ref) : ref{ ref },curent { start } {}

	iterator(const iterator& other) : curent{ other.curent }, ref{ other.ref } {}

	bool operator != (const iterator& other) const {
		return curent != other.curent;
	}

	const T& operator* () const {
		return ref.__table[curent].first;
	}

	iterator& operator = (const iterator& other) {
		curent = other.curent;
		return *this;
	}

	iterator& operator ++() {//++it;
		__repositionateCurent();
		return *this;
	}

	iterator& operator +(int a) {
		curent = min(curent + a, ref.dim);
		return *this;
	}

	friend int operator -(const iterator& a, const iterator& b) {
		return (a.curent - b.curent);
	}

	friend hashTable <T, U>;
};

template<typename T, typename H>typename hashTable<T, H>::iterator hashTable<T, H>::begin(){
	return iterator{ 0,*this };
}

template<typename T, typename H>typename hashTable<T, H>::iterator  hashTable<T, H>::end(){
	return iterator{ dim,*this };
}

struct hasher {
	int operator()(int a) const {
		return  abs(a) % 66013;
	}
};

int main(){
	hashTable <int, hasher > h;

	h.insert(10);
	h.insert(66014);
	h.insert(1);
	h.insert(1);
	h.insert(1);
	h.insert(1);
	h.insert(0);


	auto it = h.find(66014);


	while (h.find(1) != h.end())h.erase(h.find(1));

	h.erase(h.find(1000));

	for (auto e : h)cout << e << ' ';

	cout << '\n';
    return 0;
}


