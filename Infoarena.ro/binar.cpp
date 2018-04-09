#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define NMAX 2001
using namespace std;
char Matrix[NMAX][NMAX];
 
class Prob{
private:
    int N,M;
    FILE *fin,*fout;
 
    vector<int>Sol,Poz;
 
    void KindOfRadix(int line,int *p ,int dim){
 
        if(!dim || line > N+1 )return;
        if(line == N+1){
            while(dim--)Sol.push_back(*p),++p;
            return ;
        }
 
        vector<int>Multime[2];
 
        while(dim--){
            if(Matrix[line][*p-1] == '0')Multime[0].push_back(*p);
                else Multime[1].push_back(*p);
            ++p;
        }
 
        KindOfRadix(line+1,Multime[0].data(),Multime[0].size());
        KindOfRadix(line+1,Multime[1].data(),Multime[1].size());
 
    }
 
 
public:
 
    Prob(char *p,char*q){
        fin  = fopen(p,"r");
        fout = fopen(q,"w");
    }
 
    void ReadData(){
        fscanf(fin,"%d %d",&N,&M);
        fgetc(fin);
        for(int i=1;i<=N;++i)fgets(Matrix[i],NMAX,fin);
        for(int i=1;i<=M;++i)Poz.push_back(i);
        fclose(fin);
    }
 
    inline void Tipar(vector<int>Sol){
         for(auto it = Sol.begin();it!=Sol.end();++it)fprintf(fout,"%d ",*it);
    }
 
    void Write(){
       KindOfRadix(1,Poz.data(),Poz.size());
       Tipar(Sol);
 
    }
}Pr("binar.in","binar.out");
 
 
 
int main(){
    Pr.ReadData();
    Pr.Write();
    return 0;
}