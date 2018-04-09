#include <iostream>
#include <vector>
#include <bitset>
#include <fstream>
#define NMAX 100001
 
using namespace std;
 
 
 
int N;
 
vector < int > K;
 
vector < int > G[NMAX];
 
bitset < NMAX > isNotRoot;
 
vector < int > monkey;
 
void readData() {
 
    ifstream f{ "cerere.in" };
 
    f >> N;
 
    K.resize(N + 1), monkey.resize(N + 1);
 
    for (int i = 1; i <= N; ++i)f >> K[i];
 
    for(int i = 1; i < N; ++i) {
        int x, y;
        f >> x >> y; isNotRoot[y] = true;
        G[x].push_back(y);
    }
}
 
int getRoot() {
 
    for (int i = 1; i <= N; ++i) {
 
        if (isNotRoot[i])continue;
 
        return i;
    }
 
    return -1;
}
 
bitset < NMAX > viz;
 
int level = -1, levels[NMAX];
 
void DFS(int node) {
 
    levels[++level] = node;
     
    if (level == 0)monkey[node] = 0;
 
    else
        monkey[node] =(!K[node] ? 0 : 1 + monkey[levels[level - K[node]]]);
 
    for (int son : G[node]) {
        if (viz[son])continue;
        viz[son] = true; DFS(son);
    }
     
    --level;
}
 
void writeAnswer() {
    ofstream g{ "cerere.out" };
    for (int i = 1; i <= N; ++i)g << monkey[i] << ' ';
    g.close();
}
 
 
 
int main(){
    readData();
 
    DFS(getRoot());
 
    writeAnswer();
    return 0;
}