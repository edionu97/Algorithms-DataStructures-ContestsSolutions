#include <iostream>
#include <vector>
#include <cstdio>
#define NMAX 100000
using namespace std;
int Sparse[NMAX+1][17];
 
class RMQ{
private:
    vector<int>Log;
    int V[NMAX+1];
    int N,M;
    void PreprocesLog();
    void BuildSparseTable();
public:
    RMQ()
    {
        PreprocesLog();
    }
    friend void ReadAndQuerry();
}Ob;
 
void RMQ::PreprocesLog()
{
    Log.resize(NMAX+1);
    Log[1]=0;
    for(int i=2;i<=NMAX;++i)Log[i]=Log[i/2]+1;
}
 
void RMQ::BuildSparseTable()
{
    for(int i=1;i<=N;++i)Sparse[i][0]=i;
 
    for(int j=1; (1<<j)<=N ;++j)
        for(int i=1; i+(1<<j)-1<=N ;++i)
            if(V[Sparse[i][j-1]]<V[Sparse[i+(1<<(j-1))][j-1]])Sparse[i][j]=Sparse[i][j-1];
                else
                    Sparse[i][j]=Sparse[i+(1<<(j-1))][j-1];
 
}
 
void ReadAndQuerry()
{
    FILE *fin=fopen("rmq.in","r");
    FILE *fout=fopen("rmq.out","w");
    fscanf(fin,"%d %d",&Ob.N,&Ob.M);
 
    for(int i=1;i<=Ob.N;++i)fscanf(fin,"%d",&Ob.V[i]);
 
    Ob.BuildSparseTable();
 
    for(int i=1;i<=Ob.M;++i){
        int x,y;
        fscanf(fin,"%d %d",&x,&y);
        int Nrelm=y-x+1;
        int put=Ob.Log[Nrelm];
        int Pas=Nrelm-(1<<put);
        fprintf(fout,"%d\n", min(Ob.V[Sparse[x][put]],Ob.V[Sparse[x+Pas][put]]));
    }
}
 
int main()
{
    ReadAndQuerry();
    return 0;
}