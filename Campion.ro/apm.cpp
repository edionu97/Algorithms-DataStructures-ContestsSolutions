#include <algorithm>
#include <iostream>
#include <utility>
#include <cstdio>
#include <vector>
#include <queue>
#define NMAX 257
using namespace std;
priority_queue<int>H;
vector< pair<int,int> >G[NMAX];
int n;
struct Elem
{int x,y,c;
};
class Comp
{public :
 bool operator ()(Elem X,Elem Y)
 {return X.c<Y.c;}
};
void ReadApm()
{FILE *fin=fopen("apm.in","r");
 fscanf(fin,"%d",&n);
 for(int i=1;i<n;++i)
 {int x,y,c;
  fscanf(fin,"%d%d%d",&x,&y,&c);
  G[x].push_back(make_pair(y,c));
  G[y].push_back(make_pair(x,c));
 }
 int x;
 while(fscanf(fin,"%d",&x)>0)H.push(x);
 fclose(fin);
}
queue< pair<int,int> >Q;
priority_queue<Elem,vector<Elem>,Comp> H2;
void Lengh(int X)
{bool Viz[NMAX];
 for(int i=1;i<=n;++i)Viz[i]=0;
 Viz[X]=1;
 vector< pair<int,int> >::iterator it;
 for(it=G[X].begin();it!=G[X].end();++it)
 {Q.push(make_pair(it->first,it->second));
  Viz[it->first]=1;
 }
 pair<int,int>T;
 while(!Q.empty())
 {T=Q.front();
  for(it=G[T.first].begin();it!=G[T.first].end();++it)
  if(!Viz[it->first])
  {Elem val;
   val.x=X;
   val.y=it->first;
   val.c=max(it->second,T.second);
   Viz[it->first]=1;
   Q.push(make_pair(it->first,val.c));
   H2.push(val);
  }
  Q.pop();
 }
}
bool Written[NMAX][NMAX];
int NewEges[NMAX][NMAX];
void WriteSol(int ok)
{FILE *fout=fopen("apm.out","w");
 if(ok)
 for(int i=1;i<=n;++i)
  for(int j=1;j<=n;++j)
  {if(Written[i][j]||!NewEges[i][j])continue;
   fprintf(fout,"%d %d %d\n",i,j,NewEges[i][j]);
   Written[i][j]=Written[j][i]=1;
  }
 else fprintf(fout,"0");
 fclose(fout);
}
void Solve()
{for(int i=1;i<=n;++i)Lengh(i);
 int NrEx=0;
 while(!H2.empty()&&!H.empty())
 {Elem val=H2.top();
  int X=H.top();
  while(val.c>X&&!H2.empty())
  {H2.pop();
   if(H2.empty())continue;
   val=H2.top();
  }
  if(H2.empty())continue;
  if(val.c<=X&&!NewEges[val.x][val.y]&&!NewEges[val.y][val.x])
  {NewEges[val.x][val.y]=NewEges[val.y][val.x]=X;
   NrEx++;
   H.pop();
  }
  H2.pop();
 }
WriteSol(NrEx);
}

int main()
{ReadApm();
 Solve();
 return 0;
}
