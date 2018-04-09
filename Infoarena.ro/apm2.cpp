#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#define NMAX 10001
using namespace std;
 
class APM{
private:
    struct Edges{
        int x,y,c;
    }Top;
    class MinHeap{
    public:
        bool operator()(Edges A,Edges B){
            return A.c>B.c;
        }
    };
    priority_queue<Edges,vector<Edges>,MinHeap>H;
    int N,M;
    int T[NMAX];
    int FindDad(int x){
        if(T[x]==x)return x;
        T[x]=FindDad(T[x]);
        return T[x];
    }
    inline void Unite(int NodeA,int NodeB){
       T[FindDad(NodeA)]=FindDad(NodeB);
    }
protected:
    int Q;
    vector < pair<int,int> >G[NMAX];
    FILE *fout,*fin;
public:
    APM(){
        fin=fopen("apm2.in","r");
        fout=fopen("apm2.out","w");
    }
    void ReadEdges(){
        fscanf(fin,"%d %d %d",&N,&M,&Q);
        for(int i=1;i<=M;++i){
            Edges New;
            fscanf(fin,"%d %d %d",&New.x,&New.y,&New.c);
            H.push(New);
        }
    }
    void Kruskal(){
        for(int i=1;i<=N;++i)T[i]=i;
        int NrmInsert=0;
        while(NrmInsert!=N-1){
            if(FindDad(H.top().x)!=FindDad(H.top().y)){
                ++NrmInsert;
                G[H.top().x].push_back( make_pair(H.top().y,H.top().c) );
                G[H.top().y].push_back( make_pair(H.top().x,H.top().c) );
                Unite(H.top().x,H.top().y);
            }
            H.pop();
        }
    }
};
 
class Solve : private APM{
private:
    int Rez;
    int Fol[NMAX];
    bool founded;
    void Dfs(int nodeS,int nodeE,int MaxDawn,int MaxUp){
        Fol[nodeS]=true;
        if(nodeS==nodeE){
            founded=true;
            Rez=max(MaxDawn,MaxUp);
        }
        for(vector< pair<int,int> >::iterator it=G[nodeS].begin();it!=G[nodeS].end() && !founded;++it)
            if(!Fol[it->first])
                 Dfs(it->first,nodeE,MaxUp,max(MaxDawn,it->second));
    }
public:
    void Query(){
        ReadEdges();
        Kruskal();
        for(int i=1;i<=Q;++i){
            int x,y;
            fscanf(fin,"%d %d",&x,&y);
            memset(Fol,0,sizeof(Fol));
            founded=false;
            Dfs(x,y,0,G[x][0].second);
            fprintf(fout,"%d\n",--Rez);
        }
    }
}apm;
 
int main(){
    apm.Query();
    return 0;
}
© 2004-2018 Asociatia infoarenaPrima paginaDespre infoarenaTermeni si conditiiContactSari la inceputul paginii ↑
Creative Commons License Cu exceptia cazurilor in care se specifica altfel, continutul site-ului infoarena
este publicat sub licenta Creative Commons Attribution-Non