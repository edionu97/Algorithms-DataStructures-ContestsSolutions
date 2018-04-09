#include <iostream>
#include <fstream>
using namespace std;
ifstream f("joc17.in");
ofstream g("joc17.out");
long a[101][101],n,m;
int x[101],y[101];
char t[101][101];
void citire()
{f>>n;
 f>>m;
 f.get();
 for(int i=1;i<=n;i++)f.getline(t[i],101);
 for(int i=1;i<=n;i++)
 for(int j=0;j<m;j++)
 {if(t[i][j]=='0')a[i][j+1]=0;
  else a[i][j+1]=1;
  if(a[i][j+1])x[i]++,y[j+1]++;
 }
}
int val(int b,int c,int i,int j)
{int nr=0;
 if(a[c][j+1]&&a[c][j+2])nr++;
 if(a[i][j+1]&&a[i][j+2])nr++;
 if(a[i][j-1]&&a[i][j-2])nr++;
 if(a[c][j-1]&&a[c][j-2])nr++;
 if(a[b][j+1]&&a[b][j+2])nr++;
 if(a[i][j-1]&&a[i][j+1])nr++;
 if(a[b][j-1]&&a[b][j-2])nr++;
 if(a[c][j-1]&&a[c][j+1])nr++;
 if(a[b][j-1]&&a[i][j+1])nr++;
 if(a[b][j+1]&&a[c][j-1])nr++;
 return nr;
}
int vall(int b,int c,int i,int j)
{int nr=0;
 if(a[i-1][j]&&a[i+1][c])nr++;
 if(a[i-1][b]&&a[i+1][j])nr++;
 return nr;
}
void rez(int n,int m)
{int i,j,nr=0;
 for(j=1;j<=m;j++)
  if(y[j]>=3)
 for(i=1;i<=n;i++)
  if(a[i][j])
  {int b=i+1,c=i+2;
   if(c>n)break;
   if(a[b][j]&&a[c][j])nr+=val(b,c,i,j);
  }
 for(i=1;i<=n;i++)
  if(x[i]>=3)
 for(j=1;j<=m;j++)
  if(a[i][j])
  {int b=j-1,c=j+1;
   if(c>m)break;
   if(a[i][b]&&a[i][c])nr+=vall(b,c,i,j);
  }
 g<<nr;
}
int main()
{citire();
rez(n,m);

    return 0;
}
