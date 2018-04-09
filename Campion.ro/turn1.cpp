#include <cstdio>
#include <vector>
#include <queue>
#define NMAX 10001
using namespace std;
vector<int>G[NMAX];
int n,m;
void ReadGraph()
{FILE *fin=fopen("turn1.in","r");
 fscanf(fin,"%d%d",&n,&m);
 int x,y;
 for(int i=1;i<=m;++i)
 {fscanf(fin,"%d%d",&x,&y);
  if(x!=y){G[x].push_back(y);G[y].push_back(x);}
 }
 fclose(fin);
}
int vf1,vf2,nr1,nr2;
vector<bool>is(NMAX,0);
queue<int>Q;
int BFS(int i)
{Q.push(i);
 is[i]=1;
 int nrv=1;
 while(!Q.empty())
 {vector<int>::iterator it;
  for(it=G[Q.front()].begin();it!=G[Q.front()].end();++it)
  if(!is[*it]){
  Q.push(*it);
  ++nrv;
  is[*it]=1;
  }
  Q.pop();
 }
 return nrv;
}
void Afis()
{FILE *fout=fopen("turn1.out","w");
 for(int i=1;i<=n;++i)
 {if(!is[i])
  {m=BFS(i);
   if(m>=nr1)
   {vf2=vf1;
    nr2=nr1;
    nr1=m;
    vf1=i;
   }
  else
  if(m>nr2)
   {vf2=i;
    nr2=m;
   }
 }
 }
 if(!vf2)vf2=vf1;
fprintf(fout,"%d %d",vf1,vf2);
fclose(fout);
}
int main()
{ReadGraph();
 Afis();
    return 0;
}
