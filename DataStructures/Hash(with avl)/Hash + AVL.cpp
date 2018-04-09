// Hash + AVL.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "tree.h"


template  <typename T, typename allocator,typename _hasher >class Hash {
	static int const myDim = 66013;

private:

	allocator __table[myDim];

	_hasher __f;

public:

	void insert(const T& elem) {
		int key = __f(elem);
		if (__table[key].Find(elem))return;
		__table[key].Insert(elem);
	}

	void erase(const T& elem) {
		__table[__f(elem)].Erase(elem);
	}

	bool find(const T& elem) {
		return __table[__f(elem)].Find(elem);
	}

	class iterator;

	iterator begin();

	iterator end();

};


struct hasher {
	int operator()(int x) {
		return x % 66013;
	}
};

template <typename A, typename B, typename C>class Hash<A, B, C>::iterator {
private:

	int index;
	Hash <A, B, C>& ref;

	typename B::iterator it;

	inline bool shouldIRepositionate() const  {
		return !(it != ref.__table[index].end());
	}

	void repositionate() {

		if (index == Hash<A, B, C>::myDim - 1)++index;

		while (index < Hash<A, B, C>::myDim - 1  && shouldIRepositionate()) it = ref.__table[++index].begin();
		
	}

public:
	iterator(Hash<A, B, C>& ref, typename B::iterator& it) :ref{ ref }, index{ 0 }, it{ it } { repositionate();}

	iterator(Hash<A, B, C>& ref, int index) :ref{ ref }, index{ index }, it{ ref.__table[index-1].begin() } {}

	iterator& operator ++() {//++it
		++it;

		if (shouldIRepositionate()) repositionate();
		
		return *this;
	}

	iterator operator ++(int) {//it++
		auto last = *this;
		++it;
		if (shouldIRepositionate()) repositionate();

		return last;
	}

	const A& operator* () const{
		return *it;
	}

	bool operator != (const iterator& other) {
		return index != other.index;
	}
};


template <typename A, typename B, typename C>typename Hash<A, B, C>::iterator Hash<A, B, C>::begin() {
	return iterator(*this, __table[0].begin());
}

template <typename A, typename B, typename C>typename Hash<A, B, C>::iterator Hash<A, B, C>::end() {
	return iterator(*this, Hash <A,B,C>::myDim);
}

int main(){



	Hash <int,AVL<int>,hasher> H;
	H.insert(66012);
	H.insert(12);
	H.insert(1);
	H.insert(66013);
	H.insert(66014);

	for (int i = 0; i < 1000; ++i)H.insert(i);

	for (auto e : H)cout << e << '\n';
    return 0;
}

