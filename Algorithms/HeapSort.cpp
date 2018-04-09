// HeapSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <queue>
#include <iostream>

using namespace std;


class MinHeap {
public:
	bool operator ()(const int &a, const int &b) {
		return a > b;//minheap
	}
};

priority_queue <int, vector<int>, MinHeap>H;

void HeapSort(const vector <int> &V) {
	for (auto v : V)H.push(v);
	while (!H.empty()) cout << H.top() << ' ', H.pop();
}

int main(){
	HeapSort({ 1,2,3,41,0,2,3,4,6,6 });
	cout << '\n';
    return 0;
}

