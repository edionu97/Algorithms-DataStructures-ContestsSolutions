#include <iostream>
#include <fstream>
using namespace std;
ifstream f("drenaj.in");
ofstream g("drenaj.out");
int a[102][102],n,m;
void citire()
{f>>n>>m;
for(int i=0;i<=n+1;i++)
 for(int j=0;j<=m+1;j++)a[i][j]=10001;
 for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++)f>>a[i][j];
}
bool uz[102][102],ok;
const short dx[]={0,0,-1,1};
const short dy[]={1,-1,0,0};
void calcul(int x,int y,int val)
{if(a[x][y+1]<val||a[x][y-1]<val||a[x+1][y]<val||a[x-1][y]<val)ok=1;
 uz[x][y]=1;
 for(int i=0;i<4;i++)
 {int xx=dx[i]+x;
  int yy=dy[i]+y;
  if(xx>=1&&yy>=1&&xx<=n&&yy<=m&&!uz[xx][yy])
  if(a[xx][yy]==val)calcul(xx,yy,val);
 }
}
void solve(int n,int m)
{int nr=0;
 for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++)
  {ok=0;
   if(!uz[i][j])
    {calcul(i,j,a[i][j]);
     if(!ok)nr++;
    }
 }
 g<<nr;
}
int main()
{citire();
 solve(n,m);
    return 0;
}
