#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <bitset>
#include <queue>
#define NMAX 10001
#define oo 0x3f3f3f3f
using namespace std;
vector< pair<int,int> >G[NMAX];
int n,p;
void BuildGraph(int x,int y,int val)
{G[x].push_back(make_pair(y,val));}

void ReadData()
{FILE *fin=fopen("ziduri.in","r");
 fscanf(fin,"%d %d",&n,&p);
 int nr=0;
 for(int x,i=1;i<=n*n;++i)
    {fscanf(fin,"%d",&x);
     ++nr;
     int N,E,S,V;
     S=x%2,E=(x/2)%2,N=(x/4)%2,V=(x/8)%2;
      if(nr+n<=n*n)
       if(S==0)BuildGraph(nr,nr+n,1);
      else BuildGraph(nr,nr+n,p);
      if(nr+1<=n)
       if(E==0)BuildGraph(nr,nr+1,1);
      else BuildGraph(nr,nr+1,p);
      if(nr-1>=1)
        if(V==0)BuildGraph(nr,nr-1,1);
       else BuildGraph(nr,nr-1,p);
      if(nr-n>=1)
        if(N==0)BuildGraph(nr,nr-n,1);
      else BuildGraph(nr,nr-n,p);
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
bitset<NMAX>Viz,Viz1;
priority_queue<int,vector<int>,Comp> H;
void Dijkstra(int x)
{for(int i=1;i<=n*n;++i)D[i]=oo;
 D[x]=0;
 vector< pair<int,int> >::iterator it;
 H.push(x);
 while(!H.empty())
 {while(Viz[H.top()]&&!H.empty())H.pop();
  if(H.empty())continue;
  x=H.top();
  H.pop();
  Viz[x]=1;
  for(it=G[x].begin();it!=G[x].end();++it)
    if(!Viz[it->first]&&D[it->first]>D[x]+it->second)
    {D[it->first]=D[x]+it->second;
     H.push(it->first);
    }
 }
}
vector< pair<int,int> >G2[NMAX];
void MakeOrGraph()
{for(int i=1;i<=n*n;++i)
  for(vector< pair<int,int> >::iterator it=G[i].begin();it!=G[i].end();++it)
   if(D[i]+it->second==D[it->first])G2[i].push_back(make_pair(it->first,it->second));
}
queue<int>Q;
int minim[NMAX];
void CalcMinSol(int x,int zid)
{vector<pair<int,int> >::iterator it;
 Q.push(1);

 while(!Q.empty())
 {x=Q.front();
   Viz1[1]=1;
Q.pop();
  for(it=G2[x].begin();it!=G2[x].end();++it)
    if(!Viz1[it->first])
     {if(it->second==p)minim[it->first]=minim[x]+1;
      else minim[it->first]=minim[x];
      Viz1[it->first]=1;
      Q.push(it->first);
     }
     else minim[it->first]=min(minim[x],minim[it->first]);
 }
}
//void WriteSol()
//{FILE *fout=fopen("ziduri.out","w");
 //fprintf(fout,"%d\n%d",D[n*n],mini);
 //fclose(fout);
//}
int main()
{ReadData();
 Dijkstra(1);
 MakeOrGraph();
 CalcMinSol(1,0);
 //WriteSol();
// vector<pair<int,int> >::iterator it;
 /*for(int i=1;i<=n*n;++i)
  {for(it=G[i].begin();it!=G[i].end();++it)cout<<i<<' '<<it->first<<' '<<it->second<<'\n';
  cout<<'\n';
  }*/
cout<<D[n*n];
  return 0;
}
