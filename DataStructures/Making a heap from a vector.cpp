//: Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <cassert>
#include <functional>
#include <algorithm>

using namespace std;

vector < int > T;

int N;

inline int getMaxBetweenSons(int x, int y,const function < bool(const int &, const int &) > &__cmp) {
	if (y > N) return x;
	return  !__cmp(T[x] ,T[y]) ?  x : y ;
}

inline void readData(ifstream &f) {
	f >> N;
	T.resize(N + 1);
	for_each(T.begin() + 1, T.end(), [&](int &x) {f >> x; });
}

void writeData(const vector <int >&vect) {
	for (size_t i = 1; i < vect.size(); ++i)cout << vect[i] << ' ';
	cout << '\n';
}

inline void restructurare(int dad, const function < bool(const int &, const int &) > &__cmp) {

	auto __getMaxChild = getMaxBetweenSons(2 * dad, 2 * dad + 1,__cmp);

	while (__getMaxChild <= N && !__cmp(T[__getMaxChild],T[dad])) {
		swap(T[dad], T[__getMaxChild]);
		dad = __getMaxChild;
		__getMaxChild = getMaxBetweenSons(2 * dad, 2 * dad + 1,__cmp);
	}

}

void makeHeap(const vector <int> &vect,const function < bool (const int &, const int &) > &__cmp = less<int>() ){
	if (vect.size() == 0)return;

	int levels = static_cast<int>(log2(vect.size())) ;

	while (--levels >= 0) {

		for (int i = (1 << levels); i <= (1 << (levels + 1)) - 1 ; ++i) {

			if (2 * i + 1 <= N && !__cmp(  (__cmp(T[2*i],T[2*i+1]) ? T[2*i+1] : T[2*i] ) , T[i] ) ) {
					restructurare(i,__cmp);
					continue;
			}

			if (2 * i <= N && !__cmp(T[2 * i] ,T[i]) )restructurare(i,__cmp);
		}
	}
		
}


int main(){
	readData(ifstream("val.in"));
	makeHeap(T);
	writeData(T);
	assert(is_heap(T.begin() + 1, T.end()));
    return 0;
}

