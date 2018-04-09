#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
struct Elm{
 int l,c;
};

vector<Elm>V;
vector<int>X;

inline bool cmp(Elm A,Elm B)
{
    return (A.l<B.l) || (A.l==B.l && A.c>B.c);
}

int m,n,p;

void ReadData()
{
    FILE *fin=fopen("bile6.in","r");
    fscanf(fin,"%d %d %d",&m,&n,&p);
    X.resize(n+2);
    for(int i=1;i<=p;++i){
        Elm val;
        fscanf(fin,"%d %d",&val.l,&val.c);
        V.push_back(val);
    }
    for(int i=1;i<=n;++i)fscanf(fin,"%d",&X[i]);
    fclose(fin);
}

void Solve()
{
    sort(V.begin(),V.end(),cmp);
    for(int i=0;i<p;++i){
        int el=X[V[i].c];
        if(el%2==0){
            if(V[i].c-1)X[V[i].c-1]+=el/2;
            if(V[i].c+1<=n)X[V[i].c+1]+=el/2;
        }
        else{
          if(V[i].c-1)X[V[i].c-1]+=el/2+1;
          if(V[i].c+1<=n)X[V[i].c+1]+=el/2;
        }
        X[V[i].c]=0;
    }
    FILE *fout=fopen("bile6.out","w");
    for(int i=1;i<=n;++i)fprintf(fout,"%d\n",X[i]);
    fclose(fout);
}
int main()
{
    ReadData();
    Solve();
    return 0;
}
