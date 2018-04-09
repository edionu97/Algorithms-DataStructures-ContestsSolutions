//Lee

#include <iostream>
#include <cstdio>
#include <queue>
#include <utility>
#include <fstream>
#define x first
#define y second
using namespace std;
pair<int,int>Inc,Sos;
bool a[101][101],viz[101][101];
int n,m;

void ReadData()
{
    ifstream f("date.in");
    f>>n>>m>>Inc.x>>Inc.y>>Sos.x>>Sos.y;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)f>>a[i][j];
    f.close();
}

const short dx[]={1,-1,0,0};
const short dy[]={0,0,-1,1};

int b[101][101];

queue < pair<int,int> >Q;

inline bool Cond(int x,int y)
{
    return x>=1 && y>=1 && x<=n && y<=m;
}

void Lee( pair<int,int>P)
{
    Q.push(P);
    viz[P.x][P.y]=1;
    while(!Q.empty() && !b[Sos.x][Sos.y]){
        P=Q.front();
        Q.pop();
        for(int k=0;k<4;++k){
            int xx=P.x+dx[k];
            int yy=P.y+dy[k];
            if(Cond(xx,yy) && !viz[xx][yy] && !a[xx][yy]){
                Q.push( make_pair(xx,yy) );
                b[xx][yy]=b[P.x][P.y]+1;
                viz[xx][yy]=1;
            }
        }
    }
    if(!b[Sos.x][Sos.y])cout<<"Soricelul nu ajunge la branza";
    else cout<<b[Sos.x][Sos.y];
}

int main()
{
    ReadData();
    Lee(Inc);
    return 0;
}
