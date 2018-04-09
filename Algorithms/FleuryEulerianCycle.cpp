#include <iostream>
#include <cstdio>
#include <list>
#include <stack>
#include <queue>
#include <bitset>
#include <vector>
#define NMAX 100001
#define NCHAR 100001
using namespace std;
FILE *fout=fopen("ciclueuler.out","w");
 
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
    Input_Reader &operator >> (int &number){
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
}fin("ciclueuler.in","r");
 
 
class Euler{
private:
    list <int>G[NMAX];
    int N,M;
    inline bool Degree(){
        for(int i=1;i<=N;++i)
            if(G[i].size()%2)return false;
        return true;
    }
    bitset<NMAX>Fol;
    queue <int>Q;
    void Bfs(){
        Q.push(1);
        while(!Q.empty()){
            int x=Q.front();Q.pop();
            Fol[x]=true;
            for(list<int>::iterator it=G[x].begin();it!=G[x].end();++it)
                if(!Fol[*it]){
                    Q.push(*it);
                    Fol[*it]=true;
                }
        }
    }
    bool IsConcted(){
        Bfs();
        for(int i=1;i<=N;++i)
            if(!Fol[i])return false;
        return true;
    }
    inline bool Eulerian(){
        return IsConcted() && Degree();
    }
    stack<int>S;
    vector<int>answer;
    void Find(int x,int y){
        G[x].pop_front();
        for(list<int>::iterator it=G[y].begin();it!=G[y].end();++it)
            if(*it==x){
                G[y].erase(it);
                break;
            }
    }
    void BuildCycle(int x){
        S.push(x);
        while(!S.empty()){
            x=S.top();
            if(G[x].empty()){
                answer.push_back(x);
                S.pop();
            }
            else{
                int y=G[x].front();
                Find(x,y);
                S.push(y);
            }
        }
    }
    void WriteCycle(){
            BuildCycle(1);
            for(int i=0;i<answer.size()-1;++i)fprintf(fout,"%d ",answer[i]);
    }
 
public:
    void ReadData(){
        fin>>N>>M;
        for(int i=1;i<=M;++i){
            int x,y;
            fin>>x>>y;
            G[x].push_back(y);
            G[y].push_back(x);
        }
    }
    void WriteAnswer(){
        if(!Eulerian())fprintf(fout,"-1");
            else
                WriteCycle();
    }
 
}Ob;
 
 
int main()
{
    Ob.ReadData();
    Ob.WriteAnswer();
    return 0;
}