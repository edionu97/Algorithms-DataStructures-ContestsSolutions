#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cstdio>
#include <algorithm>
#include <bitset>
#define NMAX 201
using namespace std;
vector<int>G[NMAX];
int n,m,g,k,xc,yc,p;
int v[NMAX][NMAX],Exit[NMAX][NMAX];
int SimulateGraph[NMAX][NMAX];
void Danger(int x,int y,int t)
{if(t==0)v[x][y]=1;
  else
  {v[x][y]=1;
   if(x-1>0)v[x-1][y]=1;
   if(x+1<=m)v[x+1][y]=1;
   if(y-1>0)v[x][y-1]=1;
   if(y+1<=n)v[x][y+1]=1;
   if(t==2)
   {if(x-1>0&&y-1>0)v[x-1][y-1]=1;
    if(x+1<=m&&y+1<=n)v[x+1][y+1]=1;
    if(x+1<=m&&y-1>0)v[x+1][y-1]=1;
    if(x-1>0&&y+1<=n)v[x-1][y+1]=1;
    if(x-2>0)v[x-2][y]=1;
    if(x+2<=m)v[x+2][y]=1;
    if(y-2>0)v[x][y-2]=1;
    if(y+2<=n)v[x][y+2]=1;
   }
  }
}
int nrnod;
int L[NMAX],C[NMAX];
void ReadData()
{FILE *fin=fopen("cartite.in","r");
 fscanf(fin,"%d %d %d %d %d",&p,&m,&n,&xc,&yc);
 fscanf(fin,"%d",&k);
 for(int i=1;i<=k;++i)
 {int x,y,t;
  fscanf(fin,"%d %d %d",&x,&y,&t);
  Danger(x,y,t);
 }
 fscanf(fin,"%d",&g);
 int x,y;
 for(int i=1;i<=g;++i)
 {int a,b,c,d;
  fscanf(fin,"%d %d %d %d",&a,&b,&c,&d);
  Exit[a][b]=Exit[c][d]=1;
  if(!SimulateGraph[a][b])
  {SimulateGraph[a][b]=++nrnod;
   L[nrnod]=a;
   C[nrnod]=b;
  }
  x=SimulateGraph[a][b];
  if(!SimulateGraph[c][d])
  {SimulateGraph[c][d]=++nrnod;
   L[nrnod]=c;
   C[nrnod]=d;
  }
   y=SimulateGraph[c][d];
  G[x].push_back(y);
  G[y].push_back(x);
 }
 fclose(fin);
}
const short dx[]={-1,1,0,0};
const short dy[]={0,0,-1,1};
queue< pair<int,int> >Q;
int line,column,mini;
void Lee(int x,int y)
{pair<int,int>val;
 Q.push(make_pair(x,y));
 bool ok=0;
 while(!Q.empty()&&!ok)
 {val=Q.front();
  Q.pop();
  for(int k=0;k<4;++k)
  {int xx=val.first+dx[k];
   int yy=val.second+dy[k];
   if(xx>0&&yy>0&&xx<=m&&yy<=n&&!v[xx][yy])
   {v[xx][yy]=v[val.first][val.second]+1;
    Q.push(make_pair(xx,yy));
    if(Exit[xx][yy])
    {line=xx;
     column=yy;
     mini=v[xx][yy];
     ok=1;
     break;
    }
   }
  }
 }
}
bitset<NMAX>viz;
int BackAges[NMAX][NMAX];
void DFS(int x,int tx)
{vector<int>::iterator it;
 viz[x]=true;
 for(it=G[x].begin();it!=G[x].end();++it)
    if(!viz[*it])DFS(*it,x);
    else
     if(*it!=tx)BackAges[x][*it]=BackAges[*it][x]=1;
}
FILE *fout=fopen("cartite.out","w");
int N;
inline bool Cresc(int a,int b)
{return BackAges[N][a]>BackAges[N][b];
}
void Sortare()
{for(int i=1;i<=nrnod;++i)
  {N=i;
   sort(G[i].begin(),G[i].end(),Cresc);
  }
}
bitset<NMAX>scris[NMAX];
void Euler(int start)
{vector<int>::iterator it;
int x;
 do
 {x=start;
  fprintf(fout,"%d %d\n",L[x],C[x]);
  for(it=G[x].begin();it!=G[x].end();++it)
   if(!scris[x][*it])
   {start=*it;
    scris[x][*it]=scris[*it][x]=true;
    break;
   }
  if(it==G[x].end())break;
 }while(1);
}
int main()
{ReadData();
 Lee(xc,yc);
 if(p==1)fprintf(fout,"%d %d %d",line,column,mini);
 else
 {DFS(SimulateGraph[line][column],-1);
  Sortare();
  Euler(SimulateGraph[line][column]);
 }
 fclose(fout);
 return 0;
}
