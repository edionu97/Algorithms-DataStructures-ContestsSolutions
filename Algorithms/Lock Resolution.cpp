// Lock Resolution.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <list>
#include <cstdlib>
#include <utility>
#include <bitset>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <queue>
#include <cctype>
#include <set>
#define NMAX 1000000

using namespace std;

vector < list < pair <char  , int> >  > Formula;

bitset < NMAX > Indexat;

inline size_t GetRandomIndex(int N) {
	size_t index = 0;
	index = rand() % N;
	while (index < 0 || Indexat[index])index = rand() % N;
	Indexat[index] = true;
	return index;
}

inline string Read() {
	ifstream f("val.in");
	string S;
	getline(f, S);
	return S;
}

set < string > S;

void PutIn(const string &str , const int &N) {
	list < pair <char, int > > L;
	istringstream g(str);
	string aux2,litere = ""s;

	while (getline(g, aux2, 'v')) 
		for_each(aux2.begin(), aux2.end(), [&](const char &x) {if (x != ' ')L.push_back({ x , GetRandomIndex(N) }), litere.push_back(x); });

	sort(litere.begin(), litere.end());
	if(S.find(litere) == S.end())Formula.push_back(L) , S.insert(litere);
}

inline void SplitAndPutAnIndex(const string &S) {
	istringstream f(S);
	string aux;
	while (getline(f, aux, ','))if (aux != " "s) PutIn(aux, S.size());
}

inline list < pair < char , int > > :: iterator Lower(list < pair < char, int > > &L) {
	int maxi = NMAX;
	list <pair <char, int > > ::iterator it = L.begin();
	for (auto it2 = L.begin(); it2 != L.end(); ++it2)
		if (maxi > it2->second) maxi = it2->second, it = it2;
	return it;	
}

list < pair < char, int > > Rezolva(char &ch, char &ch2, const size_t &i, const size_t &j) {
	list < pair < char, int > > L;
	for_each(Formula[i].begin(), Formula[i].end(), [&](pair < char, int > &P) { if (P.first != ch) L.push_back(P); });
	for_each(Formula[j].begin(), Formula[j].end(), [&](pair < char, int > &P) { if (P.first != ch2) L.push_back(P); });
	return L;
}

inline string LockResolution() {
	for (size_t i = 0; i < Formula.size(); ++i) 
		for (size_t j = 0; j < Formula.size(); ++j) {
			if (i == j) continue;
			auto it1 = Lower(Formula[i]), it2 = Lower(Formula[j]);
			if (toupper(it1->first) == toupper(it2->first) && it1->first != it2->first) {
				string litere;
				auto L = Rezolva(it1->first, it2->first, i, j);
				for_each(L.begin(), L.end(), [&](const pair < char, int > &P) {litere.push_back(P.first); });
				sort(litere.begin(), litere.end());
				if (S.find(litere) != S.end())continue;
				if (!L.size())return "Multimea nu este consistenta\n"s;
				Formula.push_back(L);
				S.insert(litere);
			}
		}
	return "Mulimea este consistenta\n"s;
}

int main(){
	SplitAndPutAnIndex(Read());
	cout << LockResolution();
    return 0;
}

