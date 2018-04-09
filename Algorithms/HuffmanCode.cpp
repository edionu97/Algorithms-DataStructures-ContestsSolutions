// huffman code.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <memory>
#include <vector>
#include <queue>
#include <iostream>
#include <bitset>
#include <stack>
#define MAX 2000

using namespace std;

class huffmanTree {
	static const int BYTE = 256;

	struct treeNode {

		shared_ptr < treeNode > st, dr;
		int index;
		pair <char, int > info;
		treeNode(int index, char letter, int frecv) : index{ index }, info{ letter,frecv } {}

		treeNode(int index, char letter, int frecv, shared_ptr < treeNode >&st, shared_ptr < treeNode> &dr) : index{ index }, info{ letter,frecv } {
			this->st = move(st),this->dr = move(dr);
		}

	};

	struct minHeap {
		bool operator() (const shared_ptr < treeNode > & a, const shared_ptr < treeNode > &b) {
			return a->info.second > b->info.second;
		}
	};

	priority_queue < shared_ptr < treeNode >, vector  <shared_ptr < treeNode > >, minHeap > H;

	int leafIndex;

	vector < bool >s;

	vector < bool >  v[BYTE];

	void parcurge(treeNode * root) {
		if (root == nullptr) return;

		s.push_back(0);
		parcurge(root->st.get());
		s.pop_back();

		if (root->info.first != NULL) 
			for_each(s.begin(), s.end(), [&](bool a) {
				v[root->info.first].push_back(a);
			});


		s.push_back(1);
		parcurge(root->dr.get());
		s.pop_back();
	}

	shared_ptr <treeNode > root;

public:

	void insertLetters(char letter, int frec) {
		H.push(make_shared < treeNode>(++leafIndex, letter, frec));
	}

	void buildTree() {

		while (H.size() > 1) {
			auto left = H.top();H.pop();
			auto right = H.top();H.pop();
			auto newNode = make_shared  <treeNode >(++leafIndex, NULL, left->info.second + right->info.second, left, right);		
			H.push(newNode);
		}

		root = H.top();H.pop();
	}

	const vector < bool >& getLeterCode(char letter){
		static bool used = false;
		if (!used)parcurge(root.get()), used = true;
		return v[letter];
	}

};


int main(){
	huffmanTree t;

	t.insertLetters('a', 2);
	t.insertLetters('b', 4);
	t.insertLetters('c', 45);
	t.insertLetters('d', 44);
	t.insertLetters('e', 1);
	t.insertLetters('f', 4);

	t.buildTree();
	for (auto p : t.getLeterCode('b'))cout << p;
	cout << '\n';
    return 0;
}

