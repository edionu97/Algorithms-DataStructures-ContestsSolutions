#pragma once
#pragma once
#pragma once

#include <initializer_list>
#include <stdexcept>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <memory>
#include <new>


using std::initializer_list;
using std::cout;
using std::out_of_range;
using std::unique_ptr;
using std::move;
using std::make_unique;
using std::forward_iterator_tag;
using std::max;

template < typename T > class vector {
private:
	unique_ptr < T[] > elements;
	size_t __size, __capacity;
public:

	class iterator;

	vector() {
		__size = 0, __capacity = 20, elements = make_unique <T[]>(__capacity);
	}

	vector(const initializer_list < T > &list) {
		__size = 0, __capacity = 20, elements = make_unique <T[]>(__capacity);
		for (const auto & el : list)push_back(el);
	}

	vector(const vector <T> &other) {
		__size = 0, __capacity = 20, elements = move(make_unique <T[]>(__capacity));
		for (int i = 0; i < other.size(); ++i)push_back(other[i]);
	}

	void resize(size_t atWhat) {
		__capacity = atWhat;
		auto newLocation = make_unique < T[] >(atWhat);
		for (int i = 0; i < __size; ++i) newLocation[i] = elements[i];
		elements = move(newLocation);
	}

	void push_back(const T &element) {
		if (__size == __capacity)resize(2 * __capacity);
		elements[__size++] = element;
	}

	void pop_back() {
		if (__size > 0)--__size;
	}

	void erase(typename vector <T>::iterator &it) {
		if (__size == 0)return;
		if (it.__index >= size())throw out_of_range("Index out of range");
		for (size_t p = it.__index; p < size(); ++p)elements[p] = elements[p + 1];
		--__size;
	}

	void erase(typename vector <T> ::iterator&__begin, typename vector < T> ::iterator &__end) {
		if (__size == 0)return;
		if (__begin.__index > __end.__index || __begin.__index >= size())throw out_of_range("Invalid index");
		int dif = __end.__index - __begin.__index;
		for (; dif--;) erase(__begin);
	}

	void insert(typename vector <T> ::iterator& position, const T& value) {
		if (position.__index >= size() && size())throw out_of_range("Index out of range");
		if (__size + 1 == capacity()) resize(2 * capacity());
		++__size;
		auto i = __size - 1;
		for (; i > position.__index; --i)elements[i] = elements[i - 1];
		elements[i] = value;
	}

	void clear() {
		erase(begin(), end());
	}

	T& back() {
		if (__size == 0)throw out_of_range("Index out of range");
		return elements[__size - 1];
	}

	T& operator[](size_t i) {
		if (i >= __size)throw  out_of_range("Index out of range");
		return elements[i];
	}

	const T& back() const {
		if (__size == 0)throw out_of_range("Index out of range");
		return elements[__size - 1];
	}

	const T& operator[](size_t i) const {
		if (i >= __size)throw  out_of_range("Index out of range");
		return elements[i];
	}

	vector <T> &operator = (const vector <T> &other) {
		__size = 0, __capacity = other.capacity(), elements = move(make_unique <T[]>(other.capacity()));
		for (int i = 0; i < other.size(); ++i)push_back(other[i]);
		return *this;
	}

	size_t size() const {
		return __size;
	}

	size_t capacity() const {
		return __capacity;
	}

	iterator begin();

	iterator end();
};

template < typename T > class vector <T>::iterator : public std::iterator < forward_iterator_tag, T, ptrdiff_t, T*, T&> {
private:
	size_t __index, __stop;
	vector < T > &ref;

public:

	iterator(vector < T > &refer, size_t start, size_t end) : ref{ refer } {
		__index = start, __stop = end;
	}

	iterator(iterator &other) : ref{ other.ref }, __index{ other.__index }, __stop{ other.__stop } {}

	reference operator *() {
		return ref[__index];
	}

	iterator& operator ++(int junk) {//it++
		auto el = *this;
		++__index;
		return el;
	}

	iterator& operator ++() {//++it
		++__index;
		return *this;
	}

	iterator operator +(size_t offset) {//it+a
		if (__index + offset > __stop)throw out_of_range("Index out of range");
		__index += offset;
		return *this;
	}

	bool operator != (const iterator &other) {
		return __index != other.__index;
	}

	friend vector<T>;
};

template <typename T> typename vector <T>::iterator  vector <T>::begin() {
	return iterator(*this, 0, size());
}

template <typename T> typename vector <T>::iterator vector<T>::end() {
	return iterator(*this, size(), size());
}