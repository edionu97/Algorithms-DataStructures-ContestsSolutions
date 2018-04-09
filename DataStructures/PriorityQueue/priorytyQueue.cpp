// priorityQueue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "myVector.h"
#include <iostream>
#include <algorithm>
#include <functional>
#include <cassert>

template <typename T , typename Cmp = std::less<T> >class priorityQueue {
private:
	
	vector < T > queue;
	Cmp __cmp;

	inline size_t getMaxChild(const size_t index1) const {
		if (2 * index1 + 1 >= queue.size() )return 2 * index1;
		return __cmp(queue[2 * index1], queue[2 * index1 + 1]) ? 2 * index1 + 1 : 2 * index1;
	}

	void __restructurate() {
		auto __dad = 1;
		auto son = getMaxChild(__dad);
		while (son <= queue.size() - 1 && __cmp(queue[__dad], queue[son]))std::swap(queue[__dad], queue[son]), __dad = son, son = getMaxChild(__dad);	
	}

public:
	priorityQueue() { queue.push_back(0); }

	priorityQueue(const priorityQueue &other) {
		queue.clear();
		queue.push_back(0);
		queue = other.queue;
	}

	inline void push(const T &val) {
		queue.push_back(val);
		for (auto dad = queue.size() - 1; dad > 1 && !__cmp(queue[dad], queue[dad >> 1]); dad >>= 1) std::swap(queue[dad], queue[dad >> 1]);		
	}

	inline bool empty() const {
		return queue.size() == 1;
	}

	T top() const {
		return queue[1];
	}

	inline void pop() {
		if (empty())return;
		std::swap(queue[1], queue[queue.size() - 1]);
		queue.pop_back();
		__restructurate();
	}

	priorityQueue& operator = (const priorityQueue &other) {
		queue.clear();
		queue.push_back(0);
		queue = other.queue;
		return *this;
	}

	~priorityQueue() { queue.clear(); }

};

int main(){
	priorityQueue <int> Q;

	Q.push(10);
	Q.push(-10);
	Q.push(100);
	Q.push(1000);
	Q.push(50);
	Q.push(150);
	Q.push(100);
	Q.push(10000);

	for (int i = 1; i <= 1000; ++i)Q.push(i);

	vector <int> V;
	while (!Q.empty()) {
		V.push_back(Q.top());
		Q.pop();
	}
	Q.push(1);
	Q.push(2);

	while (!Q.empty()) {
		std::cout << Q.top() << ' ';
		Q.pop();
	}

	priorityQueue < int,std::greater<int> > q;
	
	for (int i = 10000; i >= 1; --i)q.push(i);

	assert(std::is_sorted(V.begin(), V.end(), [](int a, int b) {return a > b; }));

	V.clear();

	while (!q.empty()) {
		V.push_back(q.top());
		q.pop();
	}

	std::cout << '\n';

	for (auto i = 1; i <= 100; ++i)Q.push(i);

	priorityQueue<int> q2 = Q,q3;

	while (!q2.empty()) {
		q3.push(q2.top());
		q2.pop();
	}

	Q = q3;

	while (!Q.empty()) {
		std::cout << Q.top() << ' ';
		Q.pop();
	}

	std::cout << '\n';

	assert(std::is_sorted(V.begin(), V.end()));
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	return 0;
}

