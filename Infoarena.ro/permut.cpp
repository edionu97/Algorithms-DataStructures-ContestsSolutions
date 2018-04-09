#include <iostream>
#include <cstdio>
#include <algorithm>
#include <fstream>
using namespace std;
FILE *fin = fopen("permut.in","r");
FILE *fout = fopen("permut.out","w");
 
class Permut{
private:
    int N;
    vector<long long>V1,V2;
    void Sort(){
        sort(V2.begin(),V2.end(),[](long long  a,long long  b){return a < b;});
        sort(V1.begin(),V1.end(),[](long long  a,long long  b){return a < b;});
    }
public:
    void ReadData(){
        fscanf(fin,"%d",&N);
        for(int i=1;i<=N;++i){
            long long x;
            fscanf(fin,"%lld",&x);
            V1.push_back(x);
        }
        for(int i=1;i<=N;++i){
            long long x;
            fscanf(fin,"%lld",&x);
            V2.push_back(x);
        }
        Sort();
    }
 
    inline int64_t Suma(){
        int64_t S = 0;
        for(auto i = 0 ; i < N; ++i)S=S+V1[i]*V2[i];
        return S;
    }
 
}Ob;
 
int main(){
    Ob.ReadData();
    fprintf(fout,"%lld",Ob.Suma());
    return 0;
}