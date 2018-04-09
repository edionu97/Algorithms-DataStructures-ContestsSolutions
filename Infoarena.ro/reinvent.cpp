#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#define NMAX 100001
using namespace std;
vector<int>G[NMAX];
queue< pair<int,int> >Q;
int Lengh[NMAX],Viz[NMAX],n,m,x;
FILE *fin=fopen("reinvent.in","r");
FILE *fout=fopen("reinvent.out","w");
void Read()
{fscanf(fin,"%d%d%d",&n,&m,&x);
 for(int i=1;i<=m;++i)
 {int xx,yy;
 fscanf(fin,"%d%d",&xx,&yy);
 G[xx].push_back(yy);
 G[yy].push_back(xx);
 }
 for(int i=1;i<=x;++i)
 {int val;
  fscanf(fin,"%d",&val);
  Q.push(make_pair(val,0));
  Viz[val]=val;
 }
 fclose(fin);
}
bool ok;
pair<int ,int>vf;
vector<int>::iterator it;
void BFS()
{while(!Q.empty()&&!ok)
 {vf=Q.front();
  Q.pop();
  for(it=G[vf.first].begin();it!=G[vf.first].end();++it)
   if(!Viz[*it])
   {Q.push(make_pair(*it,vf.second+1));
    Lengh[*it]=vf.second+1;
    Viz[*it]=Viz[vf.first];
   }
   else
   if(Viz[*it]!=Viz[vf.first])
   {ok=1;
    int val=Lengh[*it]+vf.second+1;
    fprintf(fout,"%d",val);
    break;
   }
 }
}
int main()
{Read();
 BFS();
 return 0;
}