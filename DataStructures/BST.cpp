// SDA.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <memory>
#include <iostream>
#include <stdexcept>
#include <iterator>
#include <random>
#include <stack>

using namespace std;

template<typename T>
struct Node {

	T info;
	unique_ptr< Node > st, dr;

	Node(const T& info) : info{ info }, st{ nullptr }, dr{ nullptr } {}
};



template<typename T>
class Tree {

private:
	unique_ptr< Node<T> > root;
	int __size;


	unique_ptr< Node<T> > __insert(unique_ptr<Node<T>>& root, const T& value) {

		if (root == nullptr)	return make_unique<Node<T>>(value);

		if (root->info == value) throw runtime_error("");

		if (root->info < value) {
			root->dr = move(__insert(root->dr, value)); 
			return move(root);							
		}

		root->st = move(__insert(root->st, value));
		return move(root);

	}

	unique_ptr< Node<T> >__deleteSon(unique_ptr<Node<T>>& root) {

		return move(root->st == nullptr ? root->dr : root->st);
	}


	unique_ptr< Node<T> >__deleteTwoSons(unique_ptr<Node<T>>& root) {

		auto left = root->st.get();

		if (left->dr == nullptr) {
			root->info = left->info;
			root->st = move(left->st);
			return move(root);
		}

		auto ptr = left->dr.get();

		while (ptr->dr != nullptr) {
			left = ptr;
			ptr = ptr->dr.get();
		}
		root->info = ptr->info;
		left->dr = move(ptr->st);

		return std::move(root);

	}


	unique_ptr< Node<T> >__erase(unique_ptr<Node<T>>& root, const T& value) {

		if (!root)return nullptr;

		if (root->info == value) {
			__size--;
			if (root->st == root->dr && root->st == nullptr)return nullptr;
			if (root->st && !root->dr || !root->st && root->dr)return move(__deleteSon(root)); 

	
			return move(__deleteTwoSons(root));

		}

		if (root->info < value) {
			root->dr = move(__erase(root->dr, value));
			return move(root);
		}
		root->st = move(__erase(root->st, value));
		return move(root);
	}

	bool __find(unique_ptr< Node<T> >& root, const T& value) {

		if (root == nullptr)return false;

		if (root->info == value)return true;

		if (root->info < value)
			return __find(root->dr, value);
		return __find(root->st, value);

	}

public:
	class Iterator;

	Tree() : __size{ 0 } {}

	void insert(const T& value) {
		try {
			root = move(__insert(root, value));
			__size++;
		}catch (...) {
			return;
		}
	}

	void erase(const T& value) {
		root = move(__erase(root, value));
	}

	int size() const {
		return __size;
	}

	bool empty()const {
		return __size == 0;
	}

	bool find(const T& value) {
		return __find(root, value);
	}

	Iterator begin();
	Iterator end();
};

template<typename T >class Tree<T>::Iterator {

private:
	Tree<T>& container;
	stack<Node<T>*> stiva;
	Node<T>* curent;

	void __goLeft() {

		while (curent != nullptr) {
			stiva.push(curent);
			curent = curent->st.get();
		}

		curent = stiva.top(),stiva.pop();
	}


public:
	Iterator(Tree<T>& container, Node<T>*root) : container{ container }, curent{ root } {}

	const T& operator*() {
		__goLeft();
		return curent->info;
	}

	Iterator&  operator++() {
		curent = curent->dr.get();
		return *this;
	}

	bool operator != (const Iterator& other) {
		return !(stiva.empty() && curent == other.curent);
	}
};

template<typename T>typename Tree<T>::Iterator Tree<T>::begin() {
	return Iterator(*this, root.get());
}

template<typename T>typename Tree<T>::Iterator Tree<T>::end() {
	return Iterator(*this, nullptr);
}



int main(){

	Tree<int> copac;
	copac.insert(18);
	copac.insert(16);
	copac.insert(17);
	copac.insert(15);
	copac.insert(10);
	copac.insert(8);
	copac.insert(12);
	copac.insert(38);
	copac.insert(34);
	copac.insert(39);
	copac.insert(36);
	copac.insert(35);
	copac.insert(40);

	//copac.erase(8);

	

	for (int i = 0; i < 1000; ++i) {
		static uniform_int_distribution < int >d(0, 4444);
		static mt19937 t{ mt19937() };

		copac.insert(d(t));
	}

	Tree<int>::Iterator it = copac.begin();

	int val = 0;
	for (auto e : copac) {
		cout << e << '\n';
		++val;

	}

	cout << '\n' << (val == copac.size()) << '\n';
		

	
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	return 0;
}

