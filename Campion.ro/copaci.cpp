#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>
#include <bitset>
#define NMAX 100001
using namespace std;
vector<int>G[NMAX];
FILE *fin=fopen("copaci3.in","r");
int n,m;
void ReadData()
{fscanf(fin,"%d %d",&n,&m);
 for(int i=1;i<n;++i)
 {int x,y;
  fscanf(fin,"%d %d",&x,&y);
  G[x].push_back(y);
  G[y].push_back(x);
 }
}
queue<int>Q;
bitset<NMAX>Uz;
int D[NMAX],maxi,Poz;
void LongestChain(int x)
{Q.push(x);
 Uz[x]=true;
 vector<int>::iterator it;
 while(!Q.empty())
 {x=Q.front();
  Q.pop();
  for(it=G[x].begin();it!=G[x].end();++it)
   if(!Uz[*it])
   {Q.push(*it);
    D[*it]=D[x]+1;
    if(maxi<D[*it])
    {Poz=*it;
     maxi=D[*it];
    }
    Uz[*it]=1;
   }
 }
}
void Solve()
{LongestChain(1);
 Q.push(Poz);
 D[Poz]=0;
 Uz[Poz]=false;
 vector<int>::iterator it;
 while(!Q.empty())
 {int x=Q.front();
  Q.pop();
  for(it=G[x].begin();it!=G[x].end();++it)
   if(Uz[*it])
   {Q.push(*it);
    D[*it]=D[x]+1;
    maxi=max(maxi,D[*it]);
    Uz[*it]=false;
   }
 }
++maxi;
}
void WriteSol()
{FILE *fout=fopen("copaci3.out","w");
 for(int i=1;i<=m;++i)
 {fscanf(fin,"%d",&n);
  if(n<=maxi)fprintf(fout,"%d\n",n-1);
  else fprintf(fout,"%d\n",maxi-1+(n-maxi)*2);
 }
 fclose(fin);
 fclose(fout);
}
int main()
{ReadData();
 Solve();
 WriteSol();
    return 0;
}
