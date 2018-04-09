#include <fstream>
using namespace std;
ifstream f("foto.in");
ofstream g("foto.out");
int a[101][101],n,m,maxi,s;
const short dx[]={0,0,-1,1};
const short dy[]={-1,1,0,0};
void citire()
{f>>n>>m;
 for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++){f>>a[i][j];if(a[i][j]==0)maxi=1;}
}
bool cond(int x,int y)
{if(x>=1&&y>=1&&x<=n&&y<=m)return 1;
 return 0;
}
void fill(int i,int j)
{int x,y,p;
 for(p=0;p<=3;p++)
 {x=i+dx[p];
  y=j+dy[p];
  if(!a[x][y]&&cond(x,y))
  {a[x][y]=1;
   s++;
   fill(x,y);
  }
 }
}
void solve(int m,int n)
{for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++)
   if(a[i][j]==0)
   {s=0;
    fill(i,j);
    if(s>maxi)maxi=s;
   }
 g<<maxi;
}
int main()
{citire();
 solve(m,n);
    return 0;
}
