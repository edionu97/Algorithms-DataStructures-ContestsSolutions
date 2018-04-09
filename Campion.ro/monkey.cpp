
#include <fstream>
#include <cstring>
using namespace std;
ifstream f("monkey.in");
ofstream g("monkey.out");
char a[21][21];
char c[256]="";
short n,u,m;
void citire()
{f>>n>>m;
 f.get();
 for(short i=1;i<=n;i++)f.getline(a[i],m+1);
 c[0]=a[1][0];
}
short v[21][21];
const short ox[4]={0,0,1,-1};
const short oy[4]={1,-1,0,0};
void back(short k,short i,short j)
{short p,x,y;
 for(p=0;p<=3;p++)
 {x=i+ox[p];
  y=j+oy[p];
  if(x>=1&&x<=n&&y>=0&&y<m)
  if(!v[x][y] && !strchr(c,a[x][y]))
  {c[k]=a[x][y];
   v[x][y]=1;
   back(k+1,x,y);
  }
 }
c[k-1]=NULL;
v[i][j]=0;
if(k>u)u=k;
}
int main()
{citire();
 back(1,1,0);
g<<u;
return 0;
}
