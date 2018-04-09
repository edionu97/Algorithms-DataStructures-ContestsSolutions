#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define HMAX 666013
#define xx first
#define yy second
#define NMAX 100001
 
using namespace std;
 
FILE * fin , *fout;
 
vector < pair < int , int > > H[NMAX];
 
inline int ProdCifre(int x) {
    auto p = 1;
    if(!x)return 0;
    while (x) {
        p *= (x % 10);
        x /= 10;
    }
    return p;
}
 
vector < pair < int, int >  > V;
 
void ReadThemAll() {
    int N;
    fin = fopen("costuri.in", "r");
    fscanf(fin, "%d", &N);
    while (N--) {
        int x;
        fscanf(fin, "%d", &x);
        auto pcif = ProdCifre(x);
        H[pcif %  HMAX].push_back({x,pcif});
    }
}
 
int Find(int cate,int prod){
    int indexProd = prod % HMAX;
    if(H[indexProd].size() <cate)return -1;
    int what = 0;
    for(auto &p : H[indexProd]){
        if(p.second != prod)continue;
        ++what;
        if(what == cate)return p.first;
    }
    return  -1;
}
 
void Answer() {
    int Q;
    fout = fopen("costuri.out","w");
    fscanf(fin,"%d",&Q);
 
    while(Q--){
        int x,y;
        fscanf(fin,"%d%d",&x,&y);
        fprintf(fout,"%d\n",Find(x,y));
    }
}
 
int main(){
    ReadThemAll();
    Answer();
    return 0;
}