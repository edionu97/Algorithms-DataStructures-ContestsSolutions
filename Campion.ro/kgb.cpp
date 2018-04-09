#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>
#include <set>
#define NMAX 1004
using namespace std;
int n;
vector<int>G[NMAX];
void ReadData()
{FILE *fin=fopen("kgb.in","r");
 fscanf(fin,"%d",&n);
 int x,y;
 while(fscanf(fin,"%d%d",&x,&y)>0)
 {G[x].push_back(y);
  G[y].push_back(x);
 }
 fclose(fin);
}
inline bool Cresc(int a,int b)
{return a<b;
}
void PrepareForDfs()
{for(int i=0;i<=n;++i)
  sort(G[i].begin(),G[i].end(),Cresc);
}
stack< pair<int,int> >S;
class Compare
{public:
  bool operator () (int a,int b)
  {return a<b;
  }
};
set<int,Compare> Myset[NMAX/2+1];
int Nrel;
int Upper[NMAX],OrdDfs[NMAX],Art[NMAX],nr;
void comp(int a,int b,int Nrel)
{pair<int,int> val;
 while(!S.empty())
 {val=S.top();
  Myset[Nrel].insert(val.first);
  Myset[Nrel].insert(val.second);
  S.pop();
  if(val.first==a&&val.second==b)break;
 }
}
void Biconex(int x,int tx)
{Upper[x]=OrdDfs[x]=++nr;
 vector<int>::iterator it;
 for(it=G[x].begin();it!=G[x].end();++it)
 {if(*it!=tx&&OrdDfs[*it]<OrdDfs[x])S.push(make_pair(x,*it));
  if(!OrdDfs[*it])
  {Biconex(*it,x);
   Upper[x]=min(Upper[x],Upper[*it]);
   if(OrdDfs[x]<=Upper[*it])
    {Art[x]=1;
     if(Upper[*it]==OrdDfs[x]&&OrdDfs[x]==1)Art[x]=0;
     comp(x,*it,++Nrel);
    }
  }
  else
   if(tx!=*it)Upper[x]=min(Upper[x],OrdDfs[*it]);
 }
}
void WriteSol()
{FILE *fout=fopen("kgb.out","w");
if(Nrel==1)fprintf(fout,"KGB este forte");
else
{fprintf(fout,"KGB nu este forte\n");
 for(int i=0;i<=n;++i)
    if(Art[i]&&G[i].size()>1)fprintf(fout,"%d ",i);
  fprintf(fout,"\n");
 fprintf(fout,"%d\n",Nrel);
 for(int i=1;i<=Nrel;++i)
 {set<int>::iterator it;
  for(it=Myset[i].begin();it!=Myset[i].end();++it)fprintf(fout,"%d ",*it);
  fprintf(fout,"\n");
 }
}
 fclose(fout);
}
int main()
{ReadData();
PrepareForDfs();
 Biconex(3,-1);
WriteSol();
    return 0;
}
