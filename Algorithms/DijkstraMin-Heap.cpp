#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <utility>
#define NMAX 50001
#define oo 0x3f3f3f3f
using namespace std;
int N,M;
vector < pair<int,int> >G[NMAX];
 
void ReadData()
{
    FILE *fin=fopen("dijkstra.in","r");
    fscanf(fin,"%d %d",&N,&M);
    for(int i=1;i<=M;++i){
        int x,y,c;
        fscanf(fin,"%d %d %d",&x,&y,&c);
        G[x].push_back( make_pair(y,c) );
    }
}
 
int D[NMAX];
 
class MinHeap{
public:
    bool operator()(int a,int b)
    {
        return D[a]>D[b];
    }
};
 
priority_queue<int,vector<int>,MinHeap>H;
 
void Dijkstra()
{
    for(int i=1;i<=N;++i)D[i]=oo;
    D[1]=0;
    H.push(1);
    while(!H.empty()){
        int X=H.top();
        H.pop();
        for(vector< pair<int,int> >::iterator it=G[X].begin();it!=G[X].end();++it)
            if(D[it->first]>D[X]+it->second){
             D[it->first]=D[X]+it->second;
             H.push(it->first);
            }
 
    }
    FILE *fout=fopen("dijkstra.out","w");
    for(int i=2;i<=N;++i)
        D[i]==oo ? fprintf(fout,"0 ") : fprintf(fout,"%d ",D[i]);
}
int main()
{
    ReadData();
    Dijkstra();
    return 0;
}