#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>
#include <utility>
#include <queue>
#define NMAX 801
#define x first
#define y second
#define oo 0x3f3f3f3f3f3f
using namespace std;

int Dmaxi[NMAX],N,M,p,mini=oo;
vector < pair<int,int> >G[NMAX];
bitset<NMAX>Uz;

void Solve1(int nod)
{queue< int >Q;
 Q.push(nod);
 Uz[nod]=true;
 int maxi=0;
 while(!Q.empty())
 {nod=Q.front();
  Q.pop();
  for(vector < pair<int,int> >::iterator it=G[nod].begin();it!=G[nod].end();++it)
    if(!Uz[it->x]&&Dmaxi[1]>=it->y)
    {Q.push(it->x);
     maxi=max(maxi,Dmaxi[it->x]);
     Uz[it->x]=1;
    }
 }
 FILE *fout=fopen("dragoni.out","w");
 fprintf(fout,"%d",maxi);
}

void ReadData()
{FILE *fin=fopen("dragoni.in","r");
 fscanf(fin,"%d %d %d",&p,&N,&M);
 for(int i=1;i<=N;++i)fscanf(fin,"%d",&Dmaxi[i]);
 for(int i=1;i<=M;++i){
    int x,y,c;
    fscanf(fin,"%d %d %d",&x,&y,&c);
    G[x].push_back(make_pair(y,c));
    G[y].push_back(make_pair(x,c));
 }
 fclose(fin);
}

int NewGraph[NMAX][NMAX];
class MinHeap
{public:
  inline bool operator()(pair<int,int>A,pair<int,int>B)
   {
       return NewGraph[A.x][A.y]>NewGraph[B.x][B.y];
   }
};

priority_queue< pair<int,int> ,vector< pair<int,int> > ,MinHeap>H;
bitset<NMAX>Viz[NMAX];

void Dijkstra()
{vector< pair<int,int> >::iterator it;
 pair<int,int>nod;
 Viz[1][1]=1;
 NewGraph[1][1]=0;
  for(it=G[1].begin();it!=G[1].end();++it)
   if(Dmaxi[1]>=it->y)
   {NewGraph[it->x][1]=it->y;
    H.push(make_pair(it->x,1));
   }
 while(!H.empty())
 {while(!H.empty()&&Viz[H.top().x][H.top().y])H.pop();
  if(H.empty())break;
  nod=H.top();
  H.pop();
  Viz[nod.x][nod.y]=1;
  for(it=G[nod.x].begin();it!=G[nod.x].end();++it)
    if(Dmaxi[nod.y]>=it->y&&!Viz[it->x][nod.y])
      if(!NewGraph[it->x][nod.y]||NewGraph[it->x][nod.y]>NewGraph[nod.x][nod.y]+it->y)
       {
          NewGraph[it->x][nod.y]=NewGraph[nod.x][nod.y]+it->y;
          H.push(make_pair(it->x,nod.y));

       }

  if(nod.y!=nod.x&&!Viz[nod.x][nod.x])
    if(!NewGraph[nod.x][nod.x]||NewGraph[nod.x][nod.x]>NewGraph[nod.x][nod.y])
  {
      NewGraph[nod.x][nod.x]=NewGraph[nod.x][nod.y];
       H.push(make_pair(nod.x,nod.x));
  }
 }
 for(int i=1;i<=N;++i)
    if(NewGraph[N][i])mini=min(mini,NewGraph[N][i]);
 FILE *fout=fopen("dragoni.out","w");
 fprintf(fout,"%d",mini);
}
int main()
{ReadData();
 p==1 ? Solve1(1) : Dijkstra();
    return 0;
}
