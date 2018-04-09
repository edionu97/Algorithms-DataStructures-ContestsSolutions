// SDA (construire arbore din RSD + SRD).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <istream>
#include <fstream>
#include <iostream>
#include <memory>
#include <cassert>

using namespace std;

vector < int > rsd, srd, poz;

int N;

inline void readData(istream&& in) {
	in >> N;

	rsd.resize(N + 1), srd.resize(N + 1), poz.resize(N + 1);

	for (int i = 1; i <= N; ++i) in >> rsd[i];

	for (int i = 1; i <= N; ++i)in >> srd[i], poz[srd[i]] = i;

}

struct node {
	int info;

	unique_ptr < node > st, dr;

	node(int info) : info{ info }{}
};

unique_ptr < node > buildTree(int leftSize, int rightSide) {
	static int index = 0;

	++index;

	if (index > N)return nullptr;

	auto rad = make_unique < node >(rsd[index]);

	int __cmp = poz[index];

	rad->st = (__cmp - 1 < leftSize ? nullptr : move(buildTree(leftSize, __cmp - 1)));

	rad->dr = (__cmp + 1 > rightSide ? nullptr : move(buildTree(__cmp + 1, rightSide)));

	return move(rad);

}

void RSD(node *newTree) {

	static int element = 0;
	if (!newTree)return;

	assert(rsd[++element] == newTree->info);

	RSD(newTree->st.get());
	RSD(newTree->dr.get());
}


int main(){

	readData(ifstream{ "val.txt" });

	auto tree = move(buildTree(1, N));

	RSD(tree.get());
	
    return 0;
}

