#include <iostream>
#include <fstream>
using namespace std;
ifstream f("wow.in");
ofstream g("wow.out");
bool lab[100][100];
int n,m,al;
short ldrum[100][100],nru[100][100];;
long ldrumt[100][100];
struct fo
{bool strat[100][100];
}fol[1500];
const short dx[]={1,-1,0,0};
const short dy[]={0,0,-1,1};

bool ok(int x,int y)
{return x>=0&&x<n&&y>=0&&y<m;
}

void Lee(int a,int b,int nre)
{int cx[100*100],cy[100*100],inc,sf;
 cx[0]=a;cy[0]=b;
 fol[nre].strat[a][b]=1;
 ldrum[a][b]=0;
 nru[a][b]++;
 inc=sf=0;
 while(inc<=sf)
 {for(int i=0;i<4;i++)
   {int x=cx[inc]+dx[i];
    int y=cy[inc]+dy[i];
    if(!lab[x][y]&&ok(x,y)&&!fol[nre].strat[x][y]&&nru[x][y]+1>nre)
    {cx[++sf]=x;
     cy[sf]=y;
     fol[nre].strat[x][y]=1;
     nru[x][y]++;
     ldrum[x][y]=ldrum[cx[inc]][cy[inc]]+1;
      ldrumt[x][y]+=ldrum[x][y];
    }
   }
  inc++;
 }
}
void citire()
{f>>n>>m>>al;
int nre=-1;
 for(int i=0;i<n;i++)
  for(int j=0;j<m;j++)f>>lab[i][j];
 for(int i=1;i<=al;i++)
 {int x,y;
  f>>x>>y;
  Lee(x,y,++nre);
 }
}
void afis()
{long mini=100*1500+1,l,c;
 for(int i=0;i<n;i++)
  for(long j=0;j<m;j++)
    if(ldrumt[i][j]<mini&&nru[i][j]==al)
    {mini=ldrumt[i][j];
     l=i;
     c=j;
    }
    else
     if(ldrumt[i][j]==mini&&nru[i][j]==al)
      if(l>i)
      {l=i;
       c=j;
      }
      else
        if(l==i&&c>j)
      {l=i;
       c=j;
      }
g<<mini<<'\n'<<l<<' '<<c;
}
int main()
{citire();
 afis();
    return 0;
}
