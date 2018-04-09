#include <iostream>
#include <vector>
#include <cstdio>
#include <fstream>
#include <cmath>
#define NMAX 66013
using namespace std;
ifstream fin("eqs.in");
ofstream fout("eqs.out");
 
class Solve{
private:
    int a,b,c,d,e;
    long long NrSol;
    vector <int>H[NMAX];
 
    int abs(int a){
        return  a < 0 ? -a:a;
    }
 
    inline void AddInHash(int x){
        int key = abs(x % NMAX);
        H[key].push_back(x);
    }
 
    long Gasit(int Rezultat){
        int Match = 0;
        int key = abs(Rezultat%NMAX);
        for (auto it = H[key].begin();it!=H[key].end();++it)
            if(*it == Rezultat)++Match;
        return Match;
    }
 
    inline int Treia(int x){
        return x*x*x;
    }
 
    inline void PreprocessTwo(){
        for(int i=-50;i<=50;++i)
            for(int j=-50;j<=50;++j)
                if(i && j)AddInHash(a*Treia(i) + b*Treia(j));
 
    }
 
    void GetMatches(){
 
        if(!a && !b && !c && !d && !e){
            NrSol = 10000000000;
            return;
        }
 
        PreprocessTwo();
 
        for(int x3 = -50 ; x3 <= 50 ; ++x3)
            for(int x4 = -50 ; x4 <= 50 ; ++x4)
                for(int x5 = -50 ; x5 <= 50 ;++x5)
                    if(x3 && x4 && x5)
                        NrSol += Gasit(-(c*Treia(x3) + d*Treia(x4)+e*Treia(x5)));
    }
public:
    inline void Citire(){
        fin>>a>>b>>c>>d>>e;
        GetMatches();
    }
 
    inline long long Sol(){
        return NrSol;
    }
 
}eqs;
 
 
 
int main(){
    eqs.Citire();
    fout<<eqs.Sol();
    return 0;
}