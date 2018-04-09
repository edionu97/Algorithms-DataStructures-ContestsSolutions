// multimap.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <list>
#include <memory>
#include <string>
#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

template < typename T, typename U>struct node {
	mutable unique_ptr < node > st, dr;

	list < U > info;

	T key;

	node(const T& key, const U& value) : key{ key } { info.push_back(value); }

	node& operator =(const node & other) {
		st = move(other.st), dr = move(other.dr), key = other.key,info = move(other.info);
		return *this;
	}
};

template < typename T, typename U> class multimap {
public:
	class iterator;

private:

	typedef node < T, U > nod;
	unique_ptr < nod > root;

	int __size;

	unique_ptr < nod > __insert(unique_ptr < nod > & root, const T& key, const U& val) {

		if (root == nullptr) return move(make_unique<nod>(key, val));

		if (root->key == key) {
			root->info.push_back(val);
			return move(root);
		}

		if (root->key > key) {
			root->st = move(__insert(root->st, key, val));
			return move(root);
		}

		root->dr = move(__insert(root->dr, key, val));

		return move(root);
	}


	bool __find(unique_ptr < nod > &root, const T& key, const U& val) {

		if (!root)return false;

		if (root->key == key) return  (std::find(root->info.begin(), root->info.end(), val) != root->info.end());

		if (root->key > key) return __find(root->st, key, val);

		return __find(root->dr, key, val);
	}

	unique_ptr < nod > deleteLeaf(unique_ptr <nod>& root, const U& val) {

		auto it = std::find(root->info.begin(), root->info.end(), val);

		if (it != root->info.end()) root->info.erase(it);

		if (!root->info.empty())return move(root);

		return nullptr;
	}

	unique_ptr < nod > deleteSon(unique_ptr <nod>& root, const U& val) {


		auto it = std::find(root->info.begin(), root->info.end(), val);

		if (it != root->info.end()) root->info.erase(it);

		if (!root->info.empty())return move(root);

		return move(root->st ? root->st : root->dr);
	}

	unique_ptr < nod > deleteTwo(unique_ptr <nod>& root, const U& val) {

		if (root->st->dr == nullptr) {

			root->key = root->st->key,root->info = move(root->st->info), root->st = move(root->st->st);

			return move(root);
		}

		auto left = root->st.get();

		while (left->dr->dr) left = left->dr.get();

		root->info = move(left->dr->info), root->key = left->dr->key;

		left->dr = move(left->dr->st);

		return move(root);

	}

	unique_ptr < nod >  __erase(unique_ptr < nod > & root, const T& key, const T& val) {

		if (!root)return nullptr;

		if (root->key == key) {
			
			--__size;

			if (!root->st && !root->dr) return move(deleteLeaf(root,val));

			if (root->st && !root->dr || root->dr && !root->st)return move(deleteSon(root,val));

		
			auto it = std::find(root->info.begin(), root->info.end(), val);

			if (it != root->info.end()) root->info.erase(it);

			if (!root->info.empty())return move(root);

			return move(deleteTwo(root,val));			
		}


		if (root->key > key) {
			root->st = move(__erase(root->st, key, val));
			return move(root);
		}

		root->dr = move(__erase(root->dr, key, val));

		return move(root);
	}


public:

	multimap() : __size{ 0 } {}

	void insert(const T& key, const U& val) {
		++__size;
		root = move(__insert(root, key, val));
	}

	bool find(const T& key, const U& val){
		return __find(root, key, val);
	}

	void erase(const T& key, const U& val) {
		root = move(__erase(root, key, val));
	}

	int size() const {
		return __size;
	}
	
	iterator begin();

	iterator end();
};

template <typename T, typename U>class multimap<T, U>::iterator {
private:

	stack < nod* > stiva;
	nod* curent;
	multimap <T, U>& ref;
	typename list < U >::iterator it;

	void leftSide() {

		while (curent) {
			stiva.push(curent), curent = curent->st.get();
		}

		if (!stiva.empty()) {
			curent = stiva.top(); stiva.pop();
			it = curent->info.begin();
		}
	}

public:

	iterator(multimap<T, U>& ref, nod* ptr) : curent{ ptr }, ref{ ref } { leftSide(); }

	pair<T, U> operator*() {
		return make_pair(curent->key, *it);
	}

	iterator& operator ++() {//++it
		if (++it != curent->info.end()) return *this;
		
		curent = curent->dr.get();
		if(curent)it = curent->info.begin();
		leftSide();

		return *this;
	}
	
	bool operator != (const iterator& other) const {
		return !stiva.empty() || curent != other.curent;
	}

};


template <typename T, typename U> typename multimap<T, U>::iterator multimap<T, U>::begin() {
	return iterator{ *this, root.get() };
}

template <typename T, typename U> typename multimap<T, U>::iterator multimap<T, U>::end() {
	return iterator{ *this, nullptr };
}


int main(){
	multimap <float, int>m;
	m.insert(10, 10);
	m.insert(10, 100);
	
	m.insert(11, 2);
	m.insert(2, 45);
	m.insert(0, 40);
	m.insert(0, 41);
	m.insert(1, 452);
	m.insert(2.5, 455);
	m.insert(2.75, 100);
	m.insert(2.64, 10);
	m.insert(1, 453);
	m.insert(144, 12);

	auto p = m.begin();

	
	
	cout << boolalpha << m.find(0, 40) << '\n' << m.find(1, 452) << '\n' << m.find(0, 42) << '\n';

	
	m.erase(10, 10);
	m.erase(10, 100);
	m.erase(2.75, 100);
	m.erase(11, 2);
	m.erase(2, 45);
	m.erase(0, 40);
	m.erase(0, 41);
	m.erase(1, 452);
	m.erase(2.5, 455);
	m.erase(2.75, 100);
	m.erase(2.64, 10);
	m.erase(1, 453);
	m.erase(144, 12);

	for (auto& el : m) {
		cout << el.first << ' ' << el.second << '\n';
	}
	

	m.insert(44, 26);

	for (auto& el : m) {
		cout << el.first << ' ' << el.second << '\n';
	}

    return 0;
}

