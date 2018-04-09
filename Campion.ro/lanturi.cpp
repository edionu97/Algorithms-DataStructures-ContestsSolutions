#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <bitset>
#include <deque>
#define NMAX 1501
#define oo 1500011
using namespace std;
vector< pair<int,int> >G[NMAX];
int n,m,x,y;
void ReadData()
{FILE *fin=fopen("lanturi.in","r");
 fscanf(fin,"%d %d %d %d",&n,&m,&x,&y);
 for(int i=1;i<=m;++i)
 {int a,b,c;
  fscanf(fin,"%d %d %d",&a,&b,&c);
  G[a].push_back(make_pair(b,c));
  G[b].push_back(make_pair(a,c));
 }
 fclose(fin);
}
int D[NMAX];
class Min_Heap
{public:
  bool operator()(int x,int y)
  {return D[x]>D[y];
  }
};
priority_queue<int,vector<int>,Min_Heap>H;
bitset<NMAX>Pus;
void Dijkstra(int vf)
{for(int i=1;i<=n;++i)D[i]=oo;
 D[vf]=0;
 Pus[vf]=1;
 vector< pair<int,int> >::iterator it;
 for(it=G[vf].begin();it!=G[vf].end();++it)
  {D[it->first]=it->second;
   H.push(it->first);
  }
  while(!H.empty())
  {while(Pus[H.top()]&&!H.empty())H.pop();
    if(H.empty())continue;
   vf=H.top();
   H.pop();
   Pus[vf]=1;
   for(it=G[vf].begin();it!=G[vf].end();++it)
     if(!Pus[it->first]&&D[vf]+it->second<D[it->first])
     {D[it->first]=D[vf]+it->second;
      H.push(it->first);
     }
  }
}
deque<int>DQ;
queue<int>Q;
vector<int>G2[NMAX];
bitset<NMAX>Viz,Fol;
void BuildNewGraph(int vf)
{vector< pair<int,int> >::iterator it;
 Q.push(vf);
 Viz[vf]=1;
 while(!Q.empty())
 {vf=Q.front();
  Q.pop();
  for(it=G[vf].begin();it!=G[vf].end();++it)
   if(!Viz[it->first])
    {if(D[it->first]==D[vf]+it->second)
     {G2[vf].push_back(it->first);
      Viz[it->first]=1;
      Q.push(it->first);
     }
    }
    else
     if(D[it->first]==D[vf]+it->second)G2[vf].push_back(it->first);
 }
}
long long Solution[NMAX];
void Topologic(int x)
{vector<int>::iterator it;
  Fol[x]=1;
 for(it=G2[x].begin();it!=G2[x].end();++it)
  if(!Fol[*it])Topologic(*it);
 DQ.push_front(x);
}
void WriteSol()
{FILE *fout=fopen("lanturi.out","w");
 fprintf(fout,"%lld",Solution[y]);
 fclose(fout);
}
void Solve(int x)
{Solution[x]=1;
 vector<int>::iterator it;
 while(!DQ.empty())
 {x=DQ.front();
  DQ.pop_front();
  for(it=G2[x].begin();it!=G2[x].end();++it)Solution[*it]+=Solution[x];
 }
}
int main()
{ReadData();
 Dijkstra(x);
 BuildNewGraph(x);
 Topologic(x);
 Solve(x);
 WriteSol();
    return 0;
}
