#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <utility>
#define NMAX 7501
using namespace std;
vector<int>G[NMAX];
int n,m,X,Y;
void ReadGraph()
{FILE *fin=fopen("graf.in","r");
 fscanf(fin,"%d%d%d%d",&n,&m,&X,&Y);
 for(int i=1;i<=m;++i)
 {int x,y;
  fscanf(fin,"%d%d",&x,&y);
  G[x].push_back(y);
  G[y].push_back(x);
 }
 fclose(fin);
}
bool Viz[NMAX];
int D[NMAX],D1[NMAX];
queue< pair<int,int> >Q;
void BFS1(int x)
{Q.push(make_pair(x,0));
 pair<int,int>val;
 vector<int>::iterator it;
 Viz[x]=1;
 D[x]=0;
 while(!Q.empty())
 {val=Q.front();
  for(it=G[val.first].begin();it!=G[val.first].end();++it)
  if(!Viz[*it])
   {Q.push(make_pair(*it,val.second+1));
    D[*it]=val.second+1;
    Viz[*it]=1;
   }
   Q.pop();
 }
}
bool Viz2[NMAX];
int Used[NMAX];
void Solve(int y)
{BFS1(X);
 Viz2[y]=1;
 pair<int,int>val;
 vector<int>::iterator it;
 Q.push(make_pair(y,0));
 D1[y]=0;
 while(!Q.empty())
 {val=Q.front();
  for(it=G[val.first].begin();it!=G[val.first].end();++it)
   if(!Viz2[*it])
   {Q.push(make_pair(*it,val.second+1));
    D1[*it]=val.second+1;
    Viz2[*it]=1;
   }
  Q.pop();
 }
}
bool Scrie[NMAX],Is[NMAX];
void WriteSol()
{FILE *fout=fopen("graf.out","w");
 for(int i=1;i<=n;++i)
 if(D[i]+D1[i]==D[Y]){++Used[D[i]];Is[i]=1;}
int nr=0;
for(int i=1;i<=n;++i)
    if(Is[i]&&Used[D[i]]==1)nr++;
 fprintf(fout,"%d\n",nr);
for(int i=1;i<=n;++i)
 if(Is[i]&&Used[D[i]]==1)fprintf(fout,"%d ",i);
fclose(fout);
}
int main()
{ReadGraph();
 Solve(Y);
 WriteSol();
 return 0;
}
