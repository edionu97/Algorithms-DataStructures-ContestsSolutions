#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>
#define NMAX 301*301
using namespace std;
vector<int>G[NMAX];
int n,m;
int A[301][301];
int Inter[NMAX];
void ReadData()
{FILE *fin=fopen("drumuri1.in","r");
 fscanf(fin,"%d",&n);
  for(int i=1;i<=n;++i)
     for(int j=1;j<=n;++j)fscanf(fin,"%d",&A[i][j]);
  for(int i=1;i<=n;++i)
     for(int j=1;j<=n;++j)
     {++m;
       if(i-1>=1&&A[i][j]<A[i-1][j]){G[m].push_back(m-n);++Inter[m-n];}
       if(j-1>=1&&A[i][j]<A[i][j-1]){G[m].push_back(m-1);++Inter[m-1];}
       if(j+1<=n&&A[i][j]<A[i][j+1]){G[m].push_back(m+1);++Inter[m+1];}
       if(i+1<=n&&A[i][j]<A[i+1][j]){G[m].push_back(m+n);++Inter[m+n];}
     }
 fclose(fin);
}
bitset<NMAX>Viz;
int NrDr[NMAX];
void Dfs(int i,int ti)
{vector<int>::iterator it;
  if(!G[i].size())++NrDr[ti];
 Viz[i]=true;
  for(it=G[i].begin();it!=G[i].end();++it)
   if(!Viz[*it])
    {Dfs(*it,i);
     NrDr[i]+=NrDr[*it];
    }
   else
    if(!G[*it].size())++NrDr[i];
    else NrDr[i]+=NrDr[*it];
}
void Calcul()
{long nr=0;
 for(int i=1;i<=m;++i)
  if(!Inter[i])
  {Dfs(i,0);
   if(!NrDr[i])++NrDr[i];
   nr+=NrDr[i];
  }
 FILE *fout=fopen("drumuri1.out","w");
 fprintf(fout,"%d",nr);
 fclose(fout);
}
int main()
{ReadData();
 Calcul();

    return 0;
}
