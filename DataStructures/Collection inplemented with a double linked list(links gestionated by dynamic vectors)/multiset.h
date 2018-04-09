#pragma once
#include "list.h"

template <typename T>class multiset {
private:
	list < T > __storeElements;

public:
	multiset() = default;

	void insert(const T& value) {
		__storeElements.push_back(value);
	}

	void erase(const T& element) {
		auto it = __storeElements.find(element);
		if (!(it != __storeElements.end()))throw std::domain_error("Element does not exist \n");
		__storeElements.erase(it);
	}

	inline bool find(const T& element) {
		return __storeElements.find(element) != __storeElements.end();
	}

	size_t size() const {
		return __storeElements.size();
	}

	inline bool empty() const {
		return size() == 0;
	}

	class iterator;

	iterator begin();

	iterator end();

	~multiset() = default;
};

template <typename T> class multiset<T>::iterator {
private:
	multiset < T > &ref;
	typename list <T>::iterator it;

public:
	iterator(multiset < T > &ref, typename list<T>::iterator &setated) : it{ setated }, ref{ ref } {}

	iterator(const iterator& other) :ref{ other.ref }, it{ other.it } {}

	T& operator*() {
		return *it;
	}

	iterator& operator ++() {
		++it;
		return *this;
	}

	iterator& operator ++(int junk) {
		auto el = *this;
		++it;
		return el;
	}

	bool operator != (const iterator &other) {
		return it != other.it;
	}

};

template<typename T>typename multiset<T>::iterator multiset<T>::begin() {
	return iterator(*this, __storeElements.begin());
}

template<typename T>typename multiset<T>::iterator multiset<T>::end() {
	return iterator(*this, __storeElements.end());
}
