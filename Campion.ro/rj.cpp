#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream f("rj.in");
ofstream g("rj.out");
short r[102][102],j[102][102],n,m,xr,yr,xj,yj;
char lab[102][102];
void citire()
{f>>n>>m;
f.get();
 for(int i=1;i<=n;i++)f.getline(lab[i],102);
 for(int i=1;i<=n;i++)
   if(strchr(lab[i],'R'))
     for(int j=0;j<m;j++)
       if(lab[i][j]=='R')
        {xr=i;yr=j;
         break;
        }
  for(int i=1;i<=n;i++)
   if(strchr(lab[i],'J'))
     for(int j=0;j<m;j++)
       if(lab[i][j]=='J')
        {xj=i;
         yj=j;
         break;
        }
}

const short dx[]={0, 1, 0, -1, -1, 1, -1, 1};
const short dy[]={1, 0, -1, 0, -1, 1,  1,-1};
bool cond(int x,int y)
{if(r[x][y]==0&&x>0&&y>=0&&x<=n&&y<m&&lab[x][y]!='X')return 1;
 return 0;
}
void lee()
{short c[102*102],d[102*102];
 int p=1,b=1;
 c[1]=xr;
 d[1]=yr;
 r[xr][yr]=1;
 while(p<=b)
 {for(int k=0;k<8;k++)
   {int x=c[p]+dx[k];
    int y=d[p]+dy[k];
    if(cond(x,y))
    {c[++b]=x;
     d[b]=y;
     r[x][y]=r[c[p]][d[p]]+1;
    }
   }
   p++;
 }
}
bool cond2(int x,int y)
{return x>0&&y<m&&y>=0&&x<=n&&lab[x][y]!='X'&&!j[x][y];
}
void solve(short xj,short yj)
{lee();
 short c[102*102],d[102*102];
 short p=1,b=1;
 c[1]=xj;
 d[1]=yj;
 j[xj][yj]=1;
 while(p<=b)
 {for(int k=0;k<8;k++)
   {int x=c[p]+dx[k];
    int y=d[p]+dy[k];
    if(cond2(x,y))
    {c[++b]=x;
     d[b]=y;
     j[x][y]=j[c[p]][d[p]]+1;
    }
   }
   p++;
 }
}
void afis(int n,int m)
{int mini=102*102,l,c;
for(int i=1;i<=n;i++)
  for(int d=0;d<m;d++)
   if(r[i][d]&&j[i][d]&&r[i][d]==j[i][d])
    if(r[i][d]<mini)
    {mini=r[i][d];
     l=i;c=d+1;
    }
g<<mini<<' '<<l<<' '<<c;
}
int main()
{citire();
solve(xj,yj);
afis(n,m);

    return 0;
}
