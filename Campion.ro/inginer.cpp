#include <iostream>
#include <fstream>
using namespace std;
ifstream f("inginer.in");
ofstream g("inginer.out");
struct elem
{short a[78][78];
}p[20];
bool mat[77][77];
short n,m;
const short dx[]={-1,1,0,0};
const short dy[]={0,0,-1,1};
bool cond(int x,int y,int ord)
{return x>-1&&y>-1&&x<=n+1&&y<=m+1&&mat[x][y]==0&&p[ord].a[x][y]==0;
}
void lee(short x1,short y1,short x2,short y2,int ord)
{short c[78*78],d[78*78];
 c[1]=x1,d[1]=y1;
 int sf=1,inc=1;
 p[ord].a[x1][y1]=1;
 while(inc<=sf&&p[ord].a[x2][y2]==0)
 {for(int k=0;k<=3;k++)
    {int x=c[inc]+dx[k];
     int y=d[inc]+dy[k];
     if(cond(x,y,ord))
     {c[++sf]=x;
      d[sf]=y;
      p[ord].a[x][y]=p[ord].a[c[inc]][d[inc]]+1;
     }
    }
  inc++;
 }
 if(p[ord].a[x2][y2])g<<p[ord].a[x2][y2]-1<<'\n';
 else g<<0<<'\n';
}
void citire()
{f>>n>>m;
 for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++)
   {char val;
    f>>val;
    if(val=='X')mat[i][j]=1;
   }
 short x1,x2,y1,y2,ord=0;
 f>>x1>>y1>>x2>>y2;
 while(x1&&x2&&y1&&y2)
 {mat[x2][y2]=0;
  lee(x1,y1,x2,y2,ord);
  mat[x2][y2]=1;
  f>>x1>>y1>>x2>>y2;
  ord++;
 }
}
int main()
{citire();
    return 0;
}
