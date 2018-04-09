// BelmanKalaba's Algorithm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <limits>
#include <vector>
#include <iostream>

using namespace std;

ifstream f("val.in");

int N, M;

vector < vector < long long > >Costuri,Solutie;

void ReadData() {
	f >> N >> M;
	Costuri.resize(N + 1), Solutie.resize(N + 1);
	for (int i = 1; i <= N; ++i) {
		Costuri[i].resize(N + 1, numeric_limits<int>::max()), Solutie[i].resize(N + 1, numeric_limits<int>::max());///initializam matricea costurilor cu numeric_limits<int>::max()

		Costuri[i][i] = 0;
	}
	
	for (int i = 1; i <= M; ++i) {
		int x, y, c;
		f >> x >> y >> c;
		Costuri[x][y] = c;//citim arcul si initial costul de a ajunge de la varful x la y il facem c(costul arcului)
	}

	f.close();

}

inline bool Egale(const int &refIndex) {
	if (refIndex == 1)return false;
	
	for (int i = 1; i <= N; ++i)
		if (Solutie[refIndex][i] != Solutie[refIndex - 1][i])return false;
	return true;
}


void GetDrum(int x,int y) {
	for (int i = 1; i <= N; ++i)
		if (Solutie[x][i] + Costuri[i][y] == Solutie[x][y] && i != y) {///nu pot exista bucle in graf
			GetDrum(x, i);
			break;
		}
	cout << y << ' ';
}

void BellmanKalaba(const int &startPoint,const int &End) {

	for (int i = 1; i <= N; ++i) Solutie[1][i] = Costuri[startPoint][i];

	int IterationNumber = 1;
	while ( !Egale(IterationNumber) ) {

		++IterationNumber;

		if (IterationNumber > N) {
			cout << "Ciclu negativ !!\n";
			return;
		}

		for (int i = 1; i <= N; ++i)
			for (int j = 1; j <= N; ++j)
				if(Solutie[IterationNumber - 1][j] != numeric_limits<int>::max() && Costuri[j][i] != numeric_limits<int>::max() && Solutie[IterationNumber - 1][j] + Costuri[j][i] < Solutie[IterationNumber][i]) 
					Solutie[IterationNumber][i] = Solutie[IterationNumber - 1][j] + Costuri[j][i];
				
	}


	cout << "Un drum este :";

	GetDrum(IterationNumber,End);

	cout << '\n';

	for (int i = 1; i <= N; ++i, cout << ' ')Solutie[IterationNumber][i] != numeric_limits<int>::max() ? cout << Solutie[IterationNumber][i] : cout << "oo";
}


int main(){
	ReadData();
	BellmanKalaba(3, 5);
	cout << '\n';
    return 0;
}

