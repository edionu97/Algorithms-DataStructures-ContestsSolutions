#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <algorithm>
#define NMAX 100001
using namespace std;
vector<int>G[NMAX];
int n,m;
void ReadData()
{FILE *fin=fopen("pamant.in","r");
 fscanf(fin,"%d %d",&n,&m);
 for(int i=1;i<=m;++i)
 {int x,y;
  fscanf(fin,"%d %d",&x,&y);
  G[x].push_back(y);
  G[y].push_back(x);
 }
 fclose(fin);
}
int Ord[NMAX],Low[NMAX],Art[NMAX],Nr;
void Biconexe(int x,int tx)
{Ord[x]=Low[x]=++Nr;
 vector<int>::iterator it;
 for(it=G[x].begin();it!=G[x].end();++it)
  if(!Ord[*it])
   {Biconexe(*it,x);
    Low[x]=min(Low[x],Low[*it]);
    if(Ord[x]<=Low[*it]&&G[x].size()>1)
     {Art[x]=1;
      if(Low[*it]==Ord[x]&&Ord[x]==1)Art[x]=0;
     }
   }
 else
  if(*it!=tx)Low[x]=min(Low[x],Ord[*it]);
}
bool Cresc(int a,int b)
{return a<b;
}
vector<int>Sol1,Sol2;
void Rez(int n)
{for(int i=1;i<=n;++i)
  {Nr=0;
    if(!Ord[i])
   {Sol1.push_back(i);
    Biconexe(i,-1);
   }
 
   if(Art[i])Sol2.push_back(i);
  }
}
void WriteSol()
{FILE *fout=fopen("pamant.out","w");
int a=Sol1.size(),b=Sol2.size();
 fprintf(fout,"%d\n",a);
 vector<int>::iterator it;
  for(it=Sol1.begin();it!=Sol1.end();++it)fprintf(fout,"%d ",*it);
 fprintf(fout,"\n%d\n",b);
  for(it=Sol2.begin();it!=Sol2.end();++it)fprintf(fout,"%d ",*it);
  fclose(fout);
}
int main()
{ReadData();
 for(int i=1;i<=n;++i)sort(G[i].begin(),G[i].end(),Cresc);
 Rez(n);
WriteSol();
    return 0;
}