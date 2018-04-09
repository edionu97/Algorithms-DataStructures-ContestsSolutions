#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#define NMAX 200001
using namespace std;
 
class APM{
private:
    FILE *fin,*fout;
    struct Edge{
        int x,y,c;
    }Top;
    class MinHeap{
        public:
            bool operator()(Edge A,Edge B){
                return A.c>B.c;
            }
    };
    priority_queue <Edge,vector<Edge>,MinHeap>H;
    vector<Edge>G;
    int T[NMAX];
    int N,M,Ctot;
    int FindDad(int node){
        if(T[node]==node)return node;
        T[node]=FindDad(T[node]);
        return T[node];
    }
    inline void Union(int nodeA,int nodeB){
        T[FindDad(nodeA)]=FindDad(nodeB);
    }
public:
    APM(){
        Ctot=0;
        fin=fopen("apm.in","r");
        fout=fopen("apm.out","w");
    }
    void ReadEdges(){
        fscanf(fin,"%d %d",&N,&M);
        for(int i=1;i<=M;++i){
            Edge New;
            fscanf(fin,"%d %d %d",&New.x,&New.y,&New.c);
            H.push(New);
        }
    }
    void Kruskall(){
        for(int i=1;i<=N;++i)T[i]=i;
        while(G.size()!=N-1){
            Top=H.top();
            H.pop();
            if(FindDad(Top.x)!=FindDad(Top.y)){
                Ctot+=Top.c;
                Union(Top.x,Top.y);
                G.push_back(Top);
            }
        }
    }
    void WriteSolution(){
        fprintf(fout,"%d\n%d\n",Ctot,N-1);
        for(vector<Edge>::iterator it=G.begin();it!=G.end();++it)fprintf(fout,"%d %d\n",it->x,it->y);
    }
}apm;
 
int main(){
    apm.ReadEdges();
    apm.Kruskall();
    apm.WriteSolution();
    return 0;
}