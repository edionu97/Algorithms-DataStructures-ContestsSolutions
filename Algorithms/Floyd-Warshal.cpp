// Floyd-Warshal.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <limits>
#include <iostream>
#include <fstream>
#define NMAX 1000

using namespace std;


namespace warshall {

	const int oo = numeric_limits<int>::max();

	vector < vector < long long > > Costuri;

	int N, M;

	inline void readData() {
		ifstream f("val.in");

		f >> N >> M;
		Costuri.resize(N + 1);

		for (int i = 1; i <= N; ++i) {
			Costuri[i].resize(N + 1, oo);
			Costuri[i][i] = 0;
		}

		while (M--) {
			int x, y, c;
			f >> x >> y >> c;
			Costuri[x][y] = c;
		}

		f.close();
	}

	vector < vector < size_t > > Dad;

	void GetDrum(int x, int y) {
		if (Dad[x][y] != x) {
			GetDrum(x, Dad[x][y]);
			cout << y << ' ';
			return;
		}

		cout << x << ' ' << y << ' ';

	}

	void floydWarshal(int startNode, int endNode) {

		Dad.resize(N + 1);
		for (int i = 1; i <= N; ++i)Dad[i].resize(N + 1, 0);

		for (int i = 1; i <= N; ++i)
			if (Costuri[startNode][i] != oo)Dad[startNode][i] = startNode;

		for (int intermediar = 1; intermediar <= N; ++intermediar)

			for (int nodStart = 1; nodStart <= N; ++nodStart) {

				if (intermediar == nodStart)continue;

				for (int nodDest = 1; nodDest <= N; ++nodDest) {

					if (intermediar == nodDest || nodDest == nodStart)continue;

					if (Costuri[nodStart][intermediar] + Costuri[intermediar][nodDest] < Costuri[nodStart][nodDest]) {
						Costuri[nodStart][nodDest] = Costuri[nodStart][intermediar] + Costuri[intermediar][nodDest];
						Dad[nodStart][nodDest] = intermediar;
					}

				}
			}

		if (Costuri[startNode][endNode] == oo) {
			cout << "Nu exista drum de la varful de plecare la cel de sosire :((\n";
			return;
		}

		cout << "Drumul de valoare minima de la vf de plecare la cel de sos are constul : " << Costuri[startNode][endNode] << '\n';
		cout << "Drum: ";
		GetDrum(startNode, endNode);

	}
}


int main(){
	using namespace warshall;
	int x, y;
	readData();
	cout << "Dati vf plecare: "; cin >> x;
	cout << "Dati vf sosire: "; cin >> y;
	floydWarshal(x, y);
	cout << '\n';
    return 0;
}

