#include <iostream>
#include <bitset>
#include <cstdio>
#include <vector>
#include <stack>
#define NMAX 200001
using namespace std;
vector<int>G[NMAX],GT[NMAX];
int n,m;
void ReadData()
{FILE *fin=fopen("ctc.in","r");
 fscanf(fin,"%d %d",&n,&m);
 for(int i=1;i<=m;++i)
 {int x,y;
  fscanf(fin,"%d %d",&x,&y);
  G[x].push_back(y);
  GT[y].push_back(x);
 }
 fclose(fin);
}
bitset<NMAX>Viz;
stack<int>S;
void DFS(int x)
{vector<int>::iterator it;
 Viz[x]=true;
 for(it=G[x].begin();it!=G[x].end();++it)
    if(!Viz[*it])DFS(*it);
 S.push(x);
}
inline void Rez()
{for(int i=1;i<=n;++i)
    if(!Viz[i])DFS(i);
}
int nr;
vector<int>Comp[NMAX];
void DFST(int x,int nr)
{Viz[x]=false;
 Comp[nr].push_back(x);
 vector<int>::iterator it;
  for(it=GT[x].begin();it!=GT[x].end();++it)
     if(Viz[*it])DFST(*it,nr);
}
void Write()
{ FILE *fout=fopen("ctc.out","w");
 fprintf(fout,"%d\n",nr);
  for(int i=1;i<=nr;++i)
   {for(vector<int>::iterator it=Comp[i].begin();it!=Comp[i].end();++it)fprintf(fout,"%d ",*it);
     fprintf(fout,"\n");
   }
}
void Calculate()
{int x;
 while(!S.empty())
 {x=S.top();
  S.pop();
  if(!Viz[x])continue;
  DFST(x,++nr);
 }
 Write();
}
int main()
{ReadData();
 Rez();
 Calculate();
    return 0;
}