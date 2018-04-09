#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
 
using namespace std;
 
vector < int > component;
 
int findDad(int x) {
    if (component[x] == x)return x;
    component[x] = findDad(component[x]);
    return component[x];
}
 
inline void unite(int x, int y) {
    int a = findDad(x), b = findDad(y);
    if(a != b) component[a] = b;
}
 
void processRequest(int type, int x, int y,FILE *fout) {
 
    if (type == 1) {
        unite(x, y);return;
    }
 
    if (findDad(x) != findDad(y)) {
        fprintf(fout, "NU\n"); return;
    }
 
    fprintf(fout, "DA\n");
}
 
inline void readData() {
 
    FILE *fin = fopen("disjoint.in", "r");
    FILE *fout = fopen("disjoint.out", "w");
 
    int N, M,val = 0;
    fscanf(fin, "%d %d", &N, &M);
 
    component.resize(N + 2);
 
    for_each(component.begin() + 1, component.end(), [&](int &x) {x = ++val;});
 
    while (M--) {
        int z, x, y;
        fscanf(fin, "%d %d %d", &z, &x, &y);
        processRequest(z, x, y,fout);   
    }
}
 
int main(){
    readData();
    return 0;
}