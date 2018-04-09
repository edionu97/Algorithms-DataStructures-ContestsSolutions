#include <iostream>
#include <cstdio>
#include <bitset>
#include <utility>
#define NMAX 251
using namespace std;
 
FILE *fin = fopen("ture.in","r");
FILE *fout = fopen("ture.out","w");
 
bitset < NMAX > Pus[NMAX];
 
int N,M,K,P;
 
inline void Fct(int &x,int &y){
 
    if (N > M) swap(x,y);
}
 
int T[NMAX][(1<<15) + 1];
 
void ReadData(){
 
    fscanf(fin,"%d %d %d %d",&N,&M,&K,&P);
    for(int i=1;i<=P;++i){
        int x,y;
        fscanf(fin,"%d %d",&x,&y);
        Fct(x,y);
        Pus[x][y] = 1;
    }
    Fct(N,M);
}
 
inline int log2(int x){
 
    int exp = 0;
    while(x > 1)exp += 1,x/=2;
    return exp;
}
 
inline int Cate(int NrCol,int Linii){
 
    int lg2 = log2(Linii),S = 0;
    for(int put = 0; put <= lg2 ; ++put){
        int ant = (1<<put) & Linii;
        if (ant && !Pus[put+1][NrCol])S += T[NrCol-1][Linii xor (1<<put)];
    }
    return S;
 
}
 
inline bool HasOnlyKBit(int x){
 
    int Nrb = 0;
    while(x){
        if (x % 2)++Nrb;
        if (Nrb > K)return false;
        x/=2;
    }
    return Nrb == K;
}
 
void DinamProg(){
 
    for (int col = 1 ; col <= M; ++ col){
        for(int put = 0; put < N; ++put)
            if(!Pus[put+1][col])T[col][1<<put] = 1;
 
        for(int linii = 1; linii < (1<<N) ;++linii)
            T[col][linii] += Cate(col,linii) + T[col-1][linii];
 
    }
 
    int S = 0;
 
    for(int linii  = 1; linii < (1<<N) ;++linii)
        if( HasOnlyKBit(linii) ) S += T[M][linii];
 
    fprintf(fout,"%d",S);
}
 
 
 
int main(){
    ReadData();
    DinamProg();
    return 0;
}