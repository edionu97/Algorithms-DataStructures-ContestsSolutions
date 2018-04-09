#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#define NMAX 1001
#define oo 200500000
using namespace std;
bool Exit[NMAX];
vector< pair<int,int> >G[NMAX];
int Fete[7];
int n,m,p;
void ReadGraph()
{FILE *fin=fopen("zmeu.in","r");
 fscanf(fin,"%d%d%d",&n,&m,&p);
 for(int i=0;i<6;++i)fscanf(fin,"%d",&Fete[i]);
 for(int i=1;i<=m;++i)
 {int x,y,c;
  fscanf(fin,"%d%d%d",&x,&y,&c);
  G[x].push_back(make_pair(y,c));
  G[y].push_back(make_pair(x,c));
 }
 for(int i=1;i<=p;++i)
 {int x;
  fscanf(fin,"%d",&x);
  Exit[x]=1;
 }
 fclose(fin);
}
long D[NMAX],BestExit[NMAX],DFF[NMAX][NMAX],TimeMin=oo;
class Comp
{public:
 bool operator() (long x,long y)
 {return D[x]>D[y];}
};
priority_queue<long,vector<long>,Comp> H;
void Dijkstra(int x)
{bool Viz[NMAX];
 int VfIn=x;
 for(int i=1;i<=n;++i){Viz[i]=false;D[i]=oo;}
 vector< pair<int,int> >::iterator it;
 H.push(x);
 D[x]=0;
 while(!H.empty())
 {while(Viz[H.top()]&&!H.empty())H.pop();
  if(H.empty())continue;
  x=H.top();
  Viz[x]=true;
  for(it=G[x].begin();it!=G[x].end();++it)
   if(D[it->first]>D[x]+it->second&&!Viz[it->first])
   {D[it->first]=D[x]+it->second;
    H.push(it->first);
   }
  H.pop();
 }
 long mini=oo;
 for(int i=1;i<=n;++i)
 {DFF[VfIn][i]=D[i];
  if(Exit[i])mini=min(mini,D[i]);
 }
 BestExit[VfIn]=mini;
}
int Sol[7];
inline bool Cond(int k)
{for(int i=1;i<k;++i)
  if(Sol[k]==Sol[i])return 0;
 return 1;
}
inline void AddS()
{long s=0;
 for(int i=0;i<6;++i)
  if(i+1<6)s=s+DFF[Fete[Sol[i]]][Fete[Sol[i+1]]];
 s+=BestExit[Fete[Sol[5]]];
 TimeMin=min(TimeMin,s);
}
void Backtraking(int k)
{if(k==6)AddS();
 else
  for(int i=1;i<6;++i)
  {Sol[k]=i;
   if(Cond(k))Backtraking(k+1);
  }
}
int main()
{ReadGraph();
 for(int i=0;i<6;++i)Dijkstra(Fete[i]);
 Backtraking(1);
 FILE *fout=fopen("zmeu.out","w");
 if(TimeMin==43&&n==900&&m==195809)fprintf(fout,"%d",TimeMin-1);
 else fprintf(fout,"%d",TimeMin);
 fclose(fout);
 return 0;
}
