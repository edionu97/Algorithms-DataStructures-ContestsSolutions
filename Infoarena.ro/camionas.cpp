#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <utility>
#define oo 300000
#define NMAX 50001
#define NCHAR 100000
using namespace std;
FILE *fout=fopen("camionas.out","w");
 
 
class Input_Reader{
private:
    FILE *in;
    char buffer[NCHAR];
    int PozInBuffer,endoffile;
    void Advance(){
        if(PozInBuffer+1==NCHAR){
            PozInBuffer=-1;
            fread(buffer,1,NCHAR,in);
            endoffile=feof(in);
        }
        ++PozInBuffer;
    }
    inline bool IsFigure(char val){
        return (val>='0' && val <='9');
    }
public:
    Input_Reader (char *p,char* type){
        in=fopen(p,type);
        fread(buffer,1,NCHAR,in);
        PozInBuffer=endoffile=0;
    }
    Input_Reader &operator >> (long &number){
        number=0;
        while(!IsFigure( buffer[PozInBuffer] ))Advance();
        while(IsFigure(buffer[PozInBuffer])){
            number=number*10+buffer[PozInBuffer]-'0';
            Advance();
        }
        return *this;
    }
    bool eof(){
        return endoffile;
    }
}fin("camionas.in","r");
 
long D[NMAX];
 
class MinHeap{
    public:
    bool operator()(long x,long y){
            return D[x]>D[y];
    }
};
 
class Prob{
private:
    vector < pair<long,long> >G[NMAX];
    long N,M,greu;
    inline bool Val(long x){
        return x<greu;
    }
    priority_queue<long,vector<long>,MinHeap>H;
    inline void Init(){
        for(long i=2;i<=N;++i)D[i]=oo;
    }
public:
    void ReadData(){
        fin>>N>>M>>greu;
        for(long i=1;i<=M;++i){
            long x,y,c;
            fin>>x>>y>>c;
            G[x].push_back( make_pair(y,Val(c)) );
            G[y].push_back( make_pair(x,Val(c)) );
        }
    }
    void Dijkstra(){
        Init();
        H.push(1);
        while(!H.empty()){
            long x=H.top();
            H.pop();
            for(vector< pair<long,long> >::iterator it=G[x].begin();it!=G[x].end();++it)
                if(D[it->first]>it->second+D[x]){
                    D[it->first]=it->second+D[x];
                    H.push(it->first);
                }
        }
    }
    inline long Get(){
        return D[N];
    }
}Ob;
 
int main(){
    Ob.ReadData();
    Ob.Dijkstra();
    fprintf(fout,"%li",Ob.Get());
    return 0;
}