#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <utility>
#include <queue>
#include <algorithm>
#define NMAX 1001
using namespace std;
vector<int>G[NMAX];
int St,D,n,m,F[NMAX][NMAX],VfC;
class Comp
{public:
 bool operator()(int x,int y)
 {return F[VfC][x]>F[VfC][y];
 }
};
inline bool Cresc(int a,int b)
{return a<b;
}
void ReadData()
{FILE *fin=fopen("trip.in","r");
 fscanf(fin,"%d %d %d %d",&St,&D,&n,&m);
 for(int i=1;i<=m;++i)
 {int x,y;
  fscanf(fin,"%d %d",&x,&y);
  G[x].push_back(y);
  G[y].push_back(x);
 }
 fclose(fin);
}
stack < pair<int,int> >S;
int Sus[NMAX],OrdDfs[NMAX],nr;
int C[NMAX][NMAX];
void AddCost(int x,int y)
{pair<int,int> X;
 X=S.top();
 if(X.first==x&&X.second==y)
  {C[x][y]=C[y][x]=2;
   S.pop();
  }
 else
 while(!S.empty())
 {X=S.top();
  S.pop();
  C[X.first][X.second]=C[X.second][X.first]=1;
   if(X.first==x&&X.second==y)break;
 }
}
void Biconex(int x,int y)
{Sus[x]=OrdDfs[x]=++nr;
 vector<int>::iterator it;
 for(it=G[x].begin();it!=G[x].end();++it)
 {if(*it!=y&&OrdDfs[*it]<OrdDfs[x])S.push(make_pair(x,*it));
  if(!OrdDfs[*it])
  {Biconex(*it,x);
   Sus[x]=min(Sus[x],Sus[*it]);
   if(Sus[*it]>=OrdDfs[x])AddCost(x,*it);
  }
  else Sus[x]=min(Sus[x],OrdDfs[*it]);
 }
}
queue<int>Q;
int Viz[2][NMAX];
bool ok=1;
void SdWay(int Start)
{vector<int>::iterator it;
 for(int i=1;i<=n;++i)sort(G[i].begin(),G[i].end(),Cresc);
 Viz[0][Start]=Start;
 Q.push(Start);
 while(!Q.empty()&&!Viz[0][D])
 {Start=Q.front();
  Q.pop();
  for(it=G[Start].begin();it!=G[Start].end();++it)
   if(!Viz[0][*it])
   {Q.push(*it);
    Viz[0][*it]=Start;
   }
 }
 if(Q.empty())ok=0;
 else
 for(int i=D;i!=St;i=Viz[0][i]){F[Viz[0][i]][i]=F[i][Viz[0][i]]=1;cout<<i<<' ';}
}
priority_queue<int,vector<int>,Comp> H[NMAX];
void MakeIndexHeap(int n)
{for(int i=1;i<=n;++i)
  for(vector<int>::iterator it=G[i].begin();it!=G[i].end();++it)
   if(C[i][*it]!=F[i][*it]&&C[i][*it])
   {VfC=i;
    H[i].push(*it);
   }
}
void DsWay(int x,int tx)
{Viz[1][x]=tx;
 vector<int>::iterator it;
 while(!H[x].empty()&&!Viz[1][St])
 {int V=H[x].top();
  H[x].pop();
  if(C[x][V]-F[x][V]>0&&!Viz[1][V])
  {F[x][V]=F[V][x]=F[x][V]+(C[x][V]-F[x][V]);
   DsWay(V,x);
   if(Viz[1][St])continue;
  }
 }
}
void WriteSol(int x,int y)
{FILE *fout=fopen("trip.out","w");
 int nrm=0;
 if(ok)
{for(int i=St;i!=D&&i;i=Viz[1][i])if(F[Viz[1][i]][i]==2)++nrm;
 fprintf(fout,"%d\n",nrm);
 for(int i=St;i!=D&&i;i=Viz[1][i])fprintf(fout,"%d ",i);
 fprintf(fout,"%d\n",D);
 for(int i=D;i!=St&&i;i=Viz[0][i])fprintf(fout,"%d ",i);
 fprintf(fout,"%d\n",St);
}
else fprintf(fout,"-1");
 fclose(fout);
}
int main()
{ReadData();
 Biconex(St,0);
 SdWay(St);
 if(ok)
 {MakeIndexHeap(n);
  DsWay(D,D);
 }
WriteSol(St,D);
 return 0;
}
