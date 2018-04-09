#include <fstream>
#include <iostream>
using namespace std;
ifstream f("alee.in");
ofstream g("alee.out");
int a[176][176],n,m,pa,pb,sa,sb;
void citire()
{f>>n>>m;
 for(int i=1;i<=m;i++)
 {int x, y;
  f>>x>>y;
  a[x][y]=1;
 }
 f>>pa>>pb>>sa>>sb;
}
const int dx[]={0,0,-1,1};
const int dy[]={1,-1,0,0};
bool cor(int x,int y)
{if(x>=1&&x<=n&&y>=1&&y<=n)return 1;
 return 0;
}
void solve(int x,int y)
{int c[175*175],d[175*175],p=2,b=2;
 c[1]=x;
 d[1]=y;
 a[x][y]=1;
 while(p<=b&&a[sa][sb]==0)
 {for(int k=0;k<=3;k++)
  {int ii,jj;
   ii=c[p-1]+dx[k];
   jj=d[p-1]+dy[k];
   if(a[ii][jj]==0&&cor(ii,jj))
   {c[b]=ii;
    d[b++]=jj;
    a[ii][jj]=a[ii-dx[k]][jj-dy[k]]+1;
   }
  }
  p++;
 }
 g<<a[sa][sb];
}
int main()
{citire();
 solve(pa,pb);

   return 0;
}
