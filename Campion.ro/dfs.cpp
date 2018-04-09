#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>
#define NMAX 1001
using namespace std;
bitset<NMAX>G[NMAX];
int n,m,NrMuc;
void ReadGraph()
{FILE *fin=fopen("dfs.in","r");
 fscanf(fin,"%d %d",&n,&m);
 NrMuc=(n*(n-1))/2-m;
 for(int i=1;i<=m;++i)
 {int x,y;
  fscanf(fin,"%d %d",&x,&y);
  G[x][y]=G[y][x]=1;
 }
 fclose(fin);
}
bitset<NMAX>Uz,Viz;
vector<int>OrdDfs;
void Dfs1(int i)
{Uz[i]=1;
 OrdDfs.push_back(i);
 for(int j=1;j<=n;++j)
    if(!Uz[j]&&G[i][j])Dfs1(j);
}
void MakeGraph()
{for(int i=1;i<=n;++i)
 for(int j=i+1;j<=n;++j)G[i][j]=G[j][i]=1;
}
void Dfs2(int i,int k)
{Viz[i]=1;
 for(int j=1;j<=n;++j)
  if(!Viz[j]&&G[i][j])
   if(j==OrdDfs[k])Dfs2(j,k+1);
   else --NrMuc;
}
void WriteSol()
{FILE *fout=fopen("dfs.out","w");
 fprintf(fout,"%d",NrMuc);
 fclose(fout);
}
int main()
{ReadGraph();
 Dfs1(1);
 MakeGraph();
 Dfs2(1,1);
 WriteSol();
    return 0;
}
