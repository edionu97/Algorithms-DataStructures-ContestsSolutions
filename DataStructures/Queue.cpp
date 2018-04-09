// Queue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <memory>
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

template < typename T >class Queue {
private:

	struct __queue {
		T info;
		unique_ptr < __queue > next;
	};
	unique_ptr < __queue > __MyStart;
	__queue *__ant;
	size_t __size;

public:

	Queue() {
		__size = 0;
	}

	void Push(const T& val);

	void Pop();

	inline bool Empty();

	inline size_t size();

	T front();
};

template <typename T > void Queue < T > :: Push(const T &val){
		if (!__size) {
			__MyStart = make_unique < __queue >();
			__MyStart->info = val;
			__ant = __MyStart.get();
		}
		else {
			auto q = make_unique < __queue  >();
			q->info = val;
			__ant->next = move(q);
			__ant = __ant->next.get();
		}
		++__size;
}

template <typename T > void Queue < T > :: Pop() {
	if (!__MyStart)return;
	__MyStart = move(__MyStart->next);
	--__size;
}

template <typename T > inline bool Queue < T > :: Empty() {
	return __size == 0;
}

template <typename T > T Queue < T >:: front() {
	return __MyStart->info;
}

template <typename T> size_t Queue < T > ::size() {
	return __size;
}


struct Studenti {
	string name;

	Studenti() {
		int __dim(6), __value(0);
		do {
			--__dim;
			while (!(__value >= 97 && __value <= 122))__value = rand() % 123;
			name.push_back((char)__value);
			__value = 0;
		} while (__dim > 0);
	}

	inline string getName() const {
		return this->name;
	}

	friend ostream &operator << (ostream &out, const Studenti &st) {
		out << st.getName() << ' ';
		return out;
	}

};

int main(){
	Queue < Studenti > Q;

	while (Q.size() != 10) Q.Push(Studenti());

	while (!Q.Empty()) {
		cout << Q.front() << '\n';
		Q.Pop();
	}
	
    return 0;
}

