#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <bitset>
#define NMAX 102
#define oo 5000550
using namespace std;
vector<int>G[NMAX];
int n,m,C[NMAX][NMAX];
void ReadGraph()
{FILE *fin=fopen("traseu.in","r");
 fscanf(fin,"%d %d",&n,&m);
 for(int i=1;i<=m;++i)
 {int x,y,c;
  fscanf(fin,"%d %d %d",&x,&y,&c);
  if(!C[x][y])
  {C[x][y]=C[y][x]=c;
   G[x].push_back(y);
   G[y].push_back(x);
  }
  else C[x][y]=C[y][x]=min(C[x][y],c);
 }
 fclose(fin);
}
int D[NMAX];
class Comp
{public:
 bool operator()(int x,int y)
 {return D[x]>D[y];
 }
};
struct Elm
{int x,y,z;
}X;
int MinSol=oo,p;
priority_queue<int,vector<int>,Comp>H;
int Tata[NMAX][NMAX],Fol[NMAX][NMAX];
bitset<NMAX>Viz[NMAX];
vector<int>T[NMAX][NMAX];
void Dijksra(int k,int x)
{for(int i=1;i<=n;++i)D[i]=oo;
 vector<int>::iterator it;
 D[x]=0;
 H.push(x);
 while(!H.empty())
 {while(Viz[k][H.top()]&&!H.empty())H.pop();
  if(H.empty())continue;
  x=H.top();
  H.pop();
  Viz[k][x]=1;
  for(it=G[x].begin();it!=G[x].end();++it)
   if(!Viz[k][*it]&&D[*it]>D[x]+C[x][*it])
   {D[*it]=D[x]+C[x][*it];
    Tata[k][*it]=x;
    H.push(*it);
   }
 }
 for(int i=1;i<=n;++i)
  if(D[i]!=oo)
   {T[k][Tata[k][i]].push_back(i);
    T[k][i].push_back(Tata[k][i]);
    Fol[Tata[k][i]][i]=Fol[i][Tata[k][i]]=k;
   }
}
queue<int>Q;
int ST[NMAX][NMAX];
void CalcMinCycle(int k,int x)
{ST[k][x]=x;
 int Vf=x;
 vector<int>::iterator it;
 for(it=T[k][x].begin();it!=T[k][x].end();++it)
  {ST[k][*it]=*it;
   Q.push(*it);
  }
 while(!Q.empty())
 {x=Q.front();
  Q.pop();
  for(it=T[k][x].begin();it!=T[k][x].end();++it)
   if(!ST[k][*it])
    {ST[k][*it]=x;
     Q.push(*it);
    }
 }
 for(int i=1;i<=n;++i)
    for(int j=i+1;j<=n;++j)
     if(Fol[i][j]!=k&&D[i]+D[j]+C[i][j]<MinSol&&C[i][j]&&ST[k][i]!=ST[k][j])
     {MinSol=D[i]+D[j]+C[i][j];
      X.x=Vf;
      X.y=i;
      X.z=j;
      p=k;
     }
}
FILE *fout=fopen("traseu.out","w");
void Drum(int k)
{if(Tata[p][k])Drum(Tata[p][k]);
 fprintf(fout,"%d ",k);
}
void IDrum(int k)
{if(k!=X.x)fprintf(fout,"%d ",k);
 if(Tata[p][k])IDrum(Tata[p][k]);
}
void Solve()
{int k=0;
 for(int i=1;i<=n;++i)
 {Dijksra(++k,i);
  CalcMinCycle(k,i);
 }
 if(MinSol==oo)fprintf(fout,"0");
 else
 {Drum(X.y);
  IDrum(X.z);
 }
 fclose(fout);
}
int main()
{ReadGraph();
 Solve();
 return 0;
}
