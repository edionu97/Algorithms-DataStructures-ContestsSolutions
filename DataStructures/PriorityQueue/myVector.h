#pragma once
#pragma once
#include <new>
#include <iterator>
#include <algorithm>


template <typename T>class vector {
private:
	size_t initCap = 10;

	T *elements;

	size_t __size;

public:
	class iterator;
	typedef typename vector<T>::iterator Iterator;

public:

	vector(std::initializer_list <T> &&lista) : elements{ nullptr }, __size{ 0 } {
		for (auto el : lista)push_back(el);
	}

	vector() : elements{ nullptr }, __size{ 0 } {
		elements = new T[initCap];
		__size = 0;
	}

	vector(const vector &other) : elements{ nullptr }, __size{ 0 } {
		elements = new T[initCap];
		for (auto i = 0; i < other.size(); ++i) push_back(other[i]);
	}

	void resize(const size_t value) {
		initCap = 2 * value;

		auto oldBlock = elements;

		elements = new T[initCap];

		for (auto i = 0; i < __size; ++i)elements[i] = oldBlock[i];

		delete[] oldBlock;
	}

	void push_back(const T& value) {
		if (elements == nullptr)elements = new T[initCap];
		if (__size == initCap)resize(2 * initCap);
		elements[__size++] = value;
	}

	void erase(const Iterator &it) {
		for (auto poz = it.position; poz < size() - 1; ++poz)elements[poz] = elements[poz + 1];
		--__size;
	}

	void insert(const Iterator &it, const T &val) {
		push_back(val);
		auto poz = __size - 1;
		while (poz != it.position) {
			--poz;
			std::swap(elements[poz], elements[poz + 1]);
		}
	}


	void erase(const Iterator & __begin, const Iterator & __end) {
		auto it{ __begin };
		int cate = (__end - __begin);
		while (cate--) erase(it);
	}


	inline void pop_back() {
		if (__size) --__size;
	}

	inline T& back() {
		if (__size <= 0)throw "error";
		return elements[__size - 1];
	}

	~vector() {
		delete[] elements;
		__size = 0;
		elements = nullptr;
		initCap = 10;
	}

	inline bool empty() const {
		return __size != 0;
	}

	inline void clear() {
		this->~vector();
	}

	inline size_t size() const {
		return __size;
	}

	T& operator [](size_t i) {
		return elements[i];
	}

	T& operator [](size_t i) const {
		return elements[i];
	}

	vector& operator = (const vector &other) {
		this->~vector();
		elements = new T[initCap];
		for (auto i = 0; i < other.size(); ++i) push_back(other[i]);
		return *this;
	}

	T at(size_t index) const {
		return this->operator[](index);
	}

	size_t capacity() const {
		return initCap;
	}

	inline iterator begin() {
		return iterator(*this, 0);
	}

	inline iterator end() {
		return iterator(*this, size());
	}


};

template <typename T>class vector<T>::iterator : public std::iterator < std::input_iterator_tag, T, ptrdiff_t, T*, T&> {
private:

	size_t position;
	vector<T> &container;

public:

	iterator(vector<T>&vect, size_t poz) : position{ poz }, container{ vect } {};

	iterator(const iterator &it) : position{ it.position }, container{ it.container } {}

	inline reference operator *() {
		return container.elements[position];
	}

	inline reference operator *() const {
		return container.elements[position];
	}

	inline iterator& operator ++() {
		++position;
		return *this;
	}

	inline iterator& operator ++(int) {
		auto __this = *this;
		++position;
		return *this;
	}

	iterator& operator = (const iterator &other) {
		this->position = other.position;
		return *this;
	}

	inline bool operator != (const iterator &other) const {
		return position != other.position;
	}

	inline bool operator == (const iterator &other) const {
		return container.elements[position] == *other;
	}

	difference_type operator - (const iterator &other) const {
		return position - other.position;
	}

	inline iterator & operator + (size_t size) {
		position += size;
		return *this;
	}

	friend vector <T>;
};




