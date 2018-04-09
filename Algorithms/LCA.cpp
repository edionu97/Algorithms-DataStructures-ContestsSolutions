#include <iostream>
#include <vector>
#include <cstdio>
#include <bitset>
#include <utility>
#define NMAX 100001
using namespace std;
 
class LCA{
private:
    vector<int>G[NMAX];
    int N,M;
    FILE *fin,*fout;
    int SparseTable[4*NMAX][20];
    int Log[4*NMAX],Niv[NMAX],First[NMAX],Parcurgere[4*NMAX];
    int DimEuler;
    bitset<NMAX>fol;
    void Dfs(int nod,int niv);
    void BuildSparse();
    int Rmq(int vf1,int vf2);
public:
    LCA(){
        DimEuler=0;
        fin=fopen("lca.in","r");
        fout=fopen("lca.out","w");
    }
    void ReadData(){
        fscanf(fin,"%d %d",&N,&M);
        for(int i=1;i<N;++i){
            int y;
            fscanf(fin,"%d",&y);
            G[i+1].push_back(y);
            G[y].push_back(i+1);
        }
    }
    void Query(){
        Dfs(1,0);
        BuildSparse();
        for(int i=1;i<=M;++i){
            int x,y;
            fscanf(fin,"%d %d",&x,&y);
            fprintf(fout,"%d\n",Rmq(x,y));
        }
    }
}Ob;
 
void LCA::Dfs(int nod,int level)
{
    fol[nod]=true;
    Parcurgere[++DimEuler]=nod;
    First[nod]=DimEuler;
    Niv[nod]=level;
    vector<int>::iterator it;
    for(it=G[nod].begin();it!=G[nod].end();++it)
        if(!fol[*it]){
            Dfs(*it,level+1);
            Parcurgere[++DimEuler]=nod;
        }
 
}
 
int LCA::Rmq(int x,int y)
{
    int a=First[x],b=First[y];
    if(a>b)swap(a,b);
    int NrElm=b-a+1;
    int Put=Log[NrElm];
    int Pas=NrElm-(1<<Put);
    return min(SparseTable[a][Put],SparseTable[a+Pas][Put]);
}
 
void LCA::BuildSparse()
{
    for(int i=1;i<=DimEuler;++i)SparseTable[i][0]=Parcurgere[i];
 
    for(int j=1;(1<<j)<=DimEuler;++j)
        for(int i=1;i+(1<<j)-1<=DimEuler;++i)
            if(Niv[SparseTable[i][j-1]]<Niv[SparseTable[i+(1<<(j-1))][j-1]])SparseTable[i][j]=SparseTable[i][j-1];
                else
                    SparseTable[i][j]=SparseTable[i+(1<<(j-1))][j-1];
 
    for(int i=2;i<=DimEuler;++i)Log[i]=Log[i/2]+1;
}
int main()
{
    Ob.ReadData();
    Ob.Query();
    return 0;
}