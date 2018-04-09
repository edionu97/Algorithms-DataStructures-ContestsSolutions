//#include "stdafx.h"
#include <fstream>
#include <vector>
#include <queue>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 5000*110001
#define NMAX 1001
using namespace std;
 
int N, M;
 
vector < int > G[NMAX], bfsLeaf;
 
int C[NMAX][NMAX];
 
inline void readData() {
    ifstream f("maxflow.in");
    f >> N >> M;
 
    while (M--) {
        int x, y, c;
        f >> x >> y >> c;
        C[x][y] = c;
        G[x].push_back(y);
        G[y].push_back(x);
        if (y == N)bfsLeaf.push_back(x);
    }
 
    f.close();
}
 
int flow[NMAX][NMAX];
int viz[NMAX];
 
inline bool roadSD() {
 
    queue < int > Q;
    memset(viz, 0, sizeof(viz));
    viz[1] = 1;
    Q.push(1);
 
    while (!Q.empty()) {
        auto node = Q.front();
        Q.pop();
         
        for (const auto vertex : G[node]) {
            if (viz[vertex] || C[node][vertex] - flow[node][vertex] <= 0 )continue;
            viz[vertex] = node;
            if (vertex == N)return true;
            Q.push(vertex);
        }
 
    }
 
    return false;
}
 
void edmundsKarp() {
 
    int maxFlow = 0;
 
    while (roadSD())
        for (const auto leaf : bfsLeaf) {
 
            if (!viz[leaf] || C[leaf][N] - flow[leaf][N] <= 0)continue;
             
            int fmin = oo;
 
            viz[N] = leaf;
 
            for (int i = N; i != 1; i = viz[i]) fmin = min(fmin, C[viz[i]][i] - flow[viz[i]][i]);
            for (int i = N; i != 1; i = viz[i])flow[viz[i]][i] += fmin, flow[i][viz[i]] -= fmin;
            maxFlow += fmin;
        }
 
    ofstream g("maxflow.out");
    g << maxFlow << '\n';
    g.close();
}
 
int main(){
    readData();
    edmundsKarp();
    return 0;
}