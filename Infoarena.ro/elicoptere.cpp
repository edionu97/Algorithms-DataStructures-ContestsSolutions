#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <queue>
#include <cstring>
#include <utility>
#include <iomanip>
#define oo 0x3f3f3f3f3f3f
using namespace std;
ifstream f("elicoptere.in");
ofstream g("elicoptere.out");
 
class Problema{
private:
    struct Point{
        double x,y;
    };
    struct Triunghi{
        Point A,B,C;
    };
    inline double DistantaDouaPuncte(Point A,Point B){
        return sqrt((B.x-A.x)*(B.x-A.x)+(B.y-A.y)*(B.y-A.y));
    }
    double orizontala(Point C,Point A,Point B){
        double coefx=A.y-B.y;
        double coefy=B.x-A.x;
        double tlib=A.x*B.y-A.y*B.x;
        Point D;
        if(!coefx)//dreapta AB este orizontala
            if(C.y==A.y)
                return Min(fabs(C.x-A.x),fabs(C.x-B.x));
            else
                return oo;
        if(!coefy)//dreapta AB este vverticala
            if(C.x==A.x)return oo;
        D.y=C.y;
        D.x=-(tlib+coefy*D.y)/coefx;
        if((A.y<=D.y && D.y<=B.y)||(B.y<=D.y && D.y<=A.y))return DistantaDouaPuncte(C,D);
        return oo;
    }
    double verticala(Point C,Point A,Point B){
        double coefx=A.y-B.y;
        double coefy=B.x-A.x;
        double tlib=A.x*B.y-A.y*B.x;
        Point D;
        if(!coefx)
            if(C.y==A.y)return oo;
        if(!coefy)//verticala
            if(C.x==A.x)return Min( fabs(C.y-A.y), fabs(C.y-B.y) );
                else
                    return oo;
        D.x=C.x;
        D.y=-(tlib+coefx*D.x)/coefy;
        if((A.x<=D.x && D.x<=B.x)||(B.x<=D.x && D.x<=A.x))return DistantaDouaPuncte(C,D);
        return oo;
    }
protected:
    Triunghi Tr[101];
    int N,V,K;
    inline double Min(double x, double y){
        return ( x<y  ? x : y);
    }
    inline double MinOrizont(Triunghi Tr1,Triunghi Tr2){
        double Mini=oo;
        Mini=Min(Mini,orizontala(Tr2.A,Tr1.A,Tr1.B)),Mini=Min(Mini,orizontala(Tr2.B,Tr1.A,Tr1.B)),Mini=Min(Mini,orizontala(Tr2.C,Tr1.A,Tr1.B));
        Mini=Min(Mini,orizontala(Tr2.A,Tr1.A,Tr1.C)),Mini=Min(Mini,orizontala(Tr2.B,Tr1.A,Tr1.C)),Mini=Min(Mini,orizontala(Tr2.C,Tr1.A,Tr1.C));
        Mini=Min(Mini,orizontala(Tr2.A,Tr1.B,Tr1.C)),Mini=Min(Mini,orizontala(Tr2.B,Tr1.B,Tr1.C)),Mini=Min(Mini,orizontala(Tr2.C,Tr1.B,Tr1.C));
        return Mini;
    }
    inline double MinVerticala(Triunghi Tr1, Triunghi Tr2){
        double Mini=oo;
        Mini=Min(Mini,verticala(Tr2.A,Tr1.A,Tr1.B)),Mini=Min(Mini,verticala(Tr2.B,Tr1.A,Tr1.B)),Mini=Min(Mini,verticala(Tr2.C,Tr1.A,Tr1.B));
        Mini=Min(Mini,verticala(Tr2.A,Tr1.A,Tr1.C)),Mini=Min(Mini,verticala(Tr2.B,Tr1.A,Tr1.C)),Mini=Min(Mini,verticala(Tr2.C,Tr1.A,Tr1.C));
        Mini=Min(Mini,verticala(Tr2.A,Tr1.B,Tr1.C)),Mini=Min(Mini,verticala(Tr2.B,Tr1.B,Tr1.C)),Mini=Min(Mini,verticala(Tr2.C,Tr1.B,Tr1.C));
        return Mini;
    }
public:
    void ReadPoints(){
        f>>V>>N>>K;
        for(int i=1;i<=N;++i)
            f>>Tr[i].A.x>>Tr[i].A.y>>Tr[i].B.x>>Tr[i].B.y>>Tr[i].C.x>>Tr[i].C.y;
    }
};
 
class Solve : public Problema{
private:
    struct Edge{
        int s,e;
        double c;
    }Aux;
    int FolInHeap[101][101];
    vector < pair <int ,double> >G[101];
    class MinHeap{
        public:
        bool operator ()(Edge A , Edge B){
            return A.c>B.c;
        }
    };
    priority_queue <Edge,vector <Edge>,MinHeap>H[101];
    void Distances(){
        for(int i=1;i<=N;++i)
            for(int j=i+1;j<=N;++j){
                double kMin=Min(MinVerticala(Tr[i],Tr[j]),MinOrizont(Tr[i],Tr[j]));
                kMin=Min(Min(MinVerticala(Tr[j],Tr[i]),MinOrizont(Tr[j],Tr[i])),kMin);
                if(kMin<=K)G[i].push_back( make_pair (j,kMin) ),G[j].push_back( make_pair (i,kMin) );
                }
            }
    double Ctot;
    vector <int>Comp[101];
    int Fol[101],Nrconex;
    void Dfs(int x,int index){
            Comp[index].push_back(x);
            Fol[x]=true;
            for(vector< pair<int,double> >::iterator it=G[x].begin();it!=G[x].end();++it)
                if(!Fol[it->first]){
                    FolInHeap[x][it->first]=FolInHeap[it->first][x]=true;
                    H[index].push( {x,it->first,it->second} );
                    Dfs(it->first,index);
                }
                else
                    if(!FolInHeap[x][it->first]){
                        H[index].push( {x,it->first,it->second} );
                        FolInHeap[x][it->first]=FolInHeap[it->first][x]=true;
                    }
    }
    inline void Conexe(){
      for(int i=1;i<=N;++i)
            if(!Fol[i])Dfs(i,++Nrconex);
    }
    inline int Calcul(int x){
        return x*(x-1)/2;
    }
    int T[101];
    int FindaDad(int x){
        if(T[x]==x)return x;
        T[x]=FindaDad(T[x]);
        return T[x];
    }
    inline void Unite(int x,int y){
        T[FindaDad(x)]=FindaDad(y);
    }
    double Kruskal(int index,int dim){
        double cost_index=0;
        int Inserted=0;
        while(Inserted!=dim-1){
           Aux=H[index].top();
           if(FindaDad(Aux.s)!=FindaDad(Aux.e)){
                cost_index+=Aux.c;
                Unite(Aux.s,Aux.e);
                ++Inserted;
            }
            H[index].pop();
        }
        return cost_index;
    }
public:
    Solve(){
        Ctot=Nrconex=0;
        memset(Fol,0,sizeof(Fol));
    }
    void Answer(){
        Distances();
        Conexe();
        int Nrvertex=0;
        switch(V){
            case 1:g<<N-Nrconex;break;
            case 2:for(int i=1;i<=Nrconex;++i)Nrvertex+=Calcul(Comp[i].size());g<<Nrvertex;break;
            case 3:{
                for(int i=1;i<=N;++i)T[i]=i;
                for(int i=1;i<=Nrconex;++i)Ctot+=Kruskal(i,Comp[i].size());
                g<<fixed<<setprecision(10)<<Ctot;
                break;
            }
        }
    }
}Ob;
 
int main(){
    Ob.ReadPoints();
    Ob.Answer();
    return 0;
}