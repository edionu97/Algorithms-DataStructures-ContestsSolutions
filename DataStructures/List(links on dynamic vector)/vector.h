#pragma once
#include <new>

template <typename T>class vector {
private:

	static const size_t DIM = 100;

	struct __array {
		T *elements;
		size_t lg, maxEl;
		__array() {
			elements = new T[DIM];
			lg = 0, maxEl = DIM;
		}
	};

	__array *__MyContainer;

	void __AddElement(const T &val);

	void __EraseElement(const size_t &poz);

	void __insert(const size_t &poz, const T &element);

	void __update(const size_t &poz, const T &element);


public:

	explicit vector();

	template <typename ...Args> vector(const Args &... a) {
		__MyContainer = new __array();
		for (auto v : { a... })push_back(v);
	};

	void Resize(const int &value);

	void push_back(const T &val);

	T back() {return __MyContainer->elements[__MyContainer->lg - 1];}

	void pop_back();

	void erase(const size_t &poz);

	void insert(const size_t &poz, const T &element);

	void update(const size_t &poz, const T &element);

	T operator [](const size_t &poz) const;

	T & operator [](const size_t &poz) {
		return __MyContainer->elements[poz];
	}

	size_t Size() const;

	class iterator;

	inline iterator begin();

	inline iterator end();

	~vector();

};

template < typename T > class  vector <T>::iterator {
private:

	T *Pointer;

public:
	iterator(T * ptr) :Pointer(ptr) {}

	iterator(const iterator &a) {
		Pointer = a.Pointer;
	}

	T operator *() {
		return *Pointer;
	}

	T operator ++() {
		++Pointer;
		return *Pointer;
	}

	T operator ++(int junk) {
		T ptr = *Pointer;
		++Pointer;
		return ptr;
	}

	bool operator != (const iterator &it) {
		return Pointer != it.Pointer;
	}

	T * operator -> () {
		return Pointer;
	}

};

template <typename T> void vector<T>::__AddElement(const T &val) {
	if (__MyContainer->lg == __MyContainer->maxEl) Resize(2 * __MyContainer->maxEl);
	__MyContainer->elements[__MyContainer->lg++] = val;
}

template <typename T> void vector<T>::__EraseElement(const size_t &poz) {
	if (!(poz >= 0 && poz < Size()))return;
	for (size_t i = poz; i < Size() - 1; ++i)__MyContainer->elements[i] = __MyContainer->elements[i + 1];
	--__MyContainer->lg;
}

template <typename T> void vector<T>::__insert(const size_t &poz, const T &element) {
	if (++__MyContainer->lg == __MyContainer->maxEl)Resize(2 * __MyContainer->maxEl);
	for (size_t i = Size() - 1; i > poz; --i)__MyContainer->elements[i] = __MyContainer->ements[i - 1];
	insert(poz, element);
}

template <typename T> void vector<T>::__update(const size_t &poz, const T &element) {
	if (!(poz >= 0 && poz < Size()))return;
	__MyContainer->elements[poz] = element;
}

template <typename T> void vector <T> ::pop_back() {
	if (Size()) --__MyContainer->lg;
}

template <typename T> void vector <T>::insert(const size_t &poz, const T &element) {
	__insert(poz, element);
}


template <typename T>  void vector<T>::erase(const size_t &poz) {
	__EraseElement(poz);
}

template <typename T> void vector <T>::push_back(const T &val) {
	__AddElement(val);
}

template <typename T> void vector <T>::Resize(const int &value) {

	T *elemente = new T[value];

	__MyContainer->maxEl = value;

	for (size_t i = 0; i < Size(); ++i) elemente[i] = __MyContainer->elements[i];

	delete[] __MyContainer->elements;

	__MyContainer->elements = elemente;

}

template <typename T>vector <T> ::vector() {
	__MyContainer = new __array;
}

template <typename T> typename vector <T> ::iterator vector<T>::begin() {
	return iterator(__MyContainer->elements);
}

template <typename T> typename vector <T>::iterator vector<T>::end() {
	return iterator(__MyContainer->elements + __MyContainer->lg);
}

template <typename T> vector <T>::~vector() {
	delete[] __MyContainer->elements;
	delete __MyContainer;
}

template <typename T>size_t vector<T>::Size() const {
	return __MyContainer->lg;
}

template <typename T> T vector<T>::operator[](const size_t &poz) const {
	return __MyContainer->elements[poz];
}

template <typename T> void vector <T>::update(const size_t &poz, const T &element) {
	__update(poz, element);
}
