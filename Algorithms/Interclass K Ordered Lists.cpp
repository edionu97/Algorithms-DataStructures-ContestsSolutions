// Interclass k ordered lists.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
#include <iostream>
#define KMAX 1000

using namespace std;

struct Pair {

	int value;
	vector <int>::iterator it;
	int listNumber;

	Pair(int value, const vector < int > ::iterator &it, int number) : value{ value }, it{ it }, listNumber{ number } {  }
};

class cmp {
public:
	bool operator () (const Pair &a, const Pair &b) {
		return a.value > b.value;
	}
};

priority_queue < Pair, vector < Pair >, cmp > Q;

vector < int > V[KMAX];

ifstream f("val.in");

int K;

void readData() {
	f >> K;

	for (int N,x,i = 1 ; i <= K; ++i) {
		f >> N;
		while (N--) {
			f >> x;
			V[i].push_back(x);
		}
	}

	f.close();
}

inline void addInHeap() {
	for (int i = 1; i <= K; ++i)Q.push({ *V[i].begin(),V[i].begin(),i });
}

vector < int > interclasedList;

void optimallInterclasing() {
	addInHeap();

	while (!Q.empty()) {
		auto i = Q.top();
		interclasedList.push_back(i.value);
		Q.pop();
		++i.it;
		if (i.it != V[i.listNumber].end()) Q.push({ *i.it,i.it,i.listNumber });
	}
}


class myFct {
public:
	void operator ()(int a, int b) {
		cout << a  + b << ' ' << '\n';
	}
};




int main(){
	//readData();
	//optimallInterclasing();
	//for (auto e : interclasedList)cout << e << ' ';
	//cout << '\n';
	
	myFct f;
	f(1, 2);
    return 0;
}

