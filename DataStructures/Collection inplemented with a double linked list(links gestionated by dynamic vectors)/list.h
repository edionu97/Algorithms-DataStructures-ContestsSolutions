#pragma once

#include "vector.h"
#include <iterator>

template <typename T> class list {
public:
	class iterator;

private:

	vector < int > ant, urm, freePosition;
	vector < T > element;
	int first, last;

	int __size = 0;

	inline size_t make_node(const T &value) {
		auto index = freePosition.back();
		freePosition.pop_back();
		urm[index] = ant[index] = -1, element[index] = value;
		return index;
	}

	void __firstNodeCase(const T&value) {

		if (freePosition.size()) {
			auto index = make_node(value);
			first = last = index;
			return;
		}

		element.push_back(value);
		urm.push_back(-1);
		ant.push_back(-1);
		first = last = 0;
	}

	void __normalAdd(const T&value) {

		if (freePosition.size()) {
			size_t i = make_node(value);
			urm[last] = i, ant[i] = last, last = i;
			return;
		}

		element.push_back(value);
		ant.push_back(last);
		urm.push_back(-1);
		urm[last] = ant.size() - 1;
		last = ant.size() - 1;
	}


	void __addInFront(const T& value) {

		if (freePosition.size()) {
			size_t index = make_node(value);
			urm[index] = first, ant[first] = index, first = index;
			return;
		}

		element.push_back(value);
		ant.push_back(-1), urm.push_back(first), ant[first] = ant.size() - 1;
		first = ant.size() - 1;
	}


	void deleteFirst() {
		freePosition.push_back(first);
		first = urm[first];
		if(first != -1)ant[first] = -1;
	}


	void deleteLast() {
		freePosition.push_back(last);
		urm[ant[last]] = -1;
		last = ant[last];
	}

	void deleteNode(int index) {
		freePosition.push_back(index);
		urm[ant[index]] = urm[index];
		ant[urm[index]] = ant[index];
	}

	void __insertAnywere(const iterator& it, const T& value) {

		auto poz = it.first;

		if (freePosition.size()) {
			auto i = make_node(value);
			urm[i] = poz, urm[ant[poz]] = i;
			ant[i] = ant[poz], ant[poz] = i;
			return;
		}

		element.push_back(value);

		ant.push_back(ant[poz]);
		urm.push_back(poz);

		urm[ant[poz]] = element.size() - 1;
		ant[poz] = element.size() - 1;
	}

public:

	list() {
		first = last = -1;
	}


	list(const initializer_list <T> &lista) {
		first = last = -1;
		for (auto& el : lista)push_back(el);
	}


	void push_back(const T& value) {
		++__size;

		if (first == -1) {
			__firstNodeCase(value);
			return;
		}

		__normalAdd(value);
	}

	void push_front(const T& value) {
		++__size;
		if (first == -1) {
			__firstNodeCase(value);
			return;
		}
		__addInFront(value);
	}

	void erase(const iterator &it) {
		if (it.first == -1)throw out_of_range("Index out of range");

		--__size;

		if (it.first == first) {
			deleteFirst(); return;
		}

		if (it.first == last) {
			deleteLast(); return;
		}

		deleteNode(it.first);
	}

	void erase(iterator __start, const iterator &__end) {

		if (__start.first == first) {
			for (; __start != __end; ++__start) {
				freePosition.push_back(__start.first);
				--__size;
			}

			first = __start.first;

			if (first != -1) {
				ant[first] = -1; return;
			}

			first = last = -1;
			return;
		}

		int incep = __start.first;

		for (; __start != __end; ++__start) {
			freePosition.push_back(__start.first);
			--__size;
		}

		urm[ant[incep]] = (__start.first != -1) ? urm[__start.first] : -1;//daca nu cumva end indica pe elementul de dupa ultimul

		if (__start.first != -1) {
			ant[__start.first] = ant[incep]; return;
		}

		last = ant[incep];
		urm[last] = -1;
	}

	void insert(const iterator &it, const T& value) {
		if (it.first == -1)throw out_of_range("Index out of range!");

		++__size;

		if (it.first == first) {
			__addInFront(value); return;
		}

		__insertAnywere(it, value);

	}

	iterator find(const T& element) {
		for (auto it = begin(); it != end(); ++it)
			if (*it == element)return it;
		return end();
	}

	iterator find(const iterator &__start, const T& element) {
		for (auto it = __start; it != end(); ++it)
			if (*it == element)return it;
		return end();
	}

	bool empty() const {
		return __size == 0;
	}


	size_t size() const {
		return __size;
	}

	iterator begin();

	iterator end();

	~list() {
		first = last = -1;
		__size = 0;
	}
};


template <typename T> class list<T>::iterator : public std::iterator < std::bidirectional_iterator_tag, T, ptrdiff_t, T*, T& > {
private:
	list<T> &ref;
	int first, last;
public:

	iterator(list<T>& ref, int first, int last) : ref{ ref }, first{ first }, last{ last } {
	}

	iterator(const iterator & other) : ref{ other.ref } {
		first = other.first, last = other.last;
	}

	reference operator *() {
		return ref.element[first];
	}

	iterator operator ++ (int junk) {//it++
		auto el = *this;
		first = ref.urm[first];
		return el;
	}

	iterator& operator --() {//--it;
		first = ref.ant[first];
		return *this;
	}

	iterator operator --(int junk) {//it--
		auto el = *this;
		first = ref.ant[first];
		return el;
	}

	iterator& operator ++ () {//++it
		first = ref.urm[first];
		return *this;
	}

	iterator& operator = (const iterator &other) {
		first = other.first, last = other.last;
		return *this;
	}

	iterator& operator +(int offset) {//it + offset
		if (offset >= ref.size())throw out_of_range("Index out of range!");
		while (offset-- > 0)first = ref.urm[first];
		return *this;
	}

	bool operator != (const iterator &other) {
		return other.first != first;
	}

	friend list<T>;
};

template <typename T> typename list<T>::iterator list<T>::begin() {
	return iterator(*this, first, last);
}

template <typename T> typename list<T>::iterator list<T>::end() {
	return iterator(*this, -1, -1);
}

