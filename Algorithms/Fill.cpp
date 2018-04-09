#include <iostream>
#include <bitset>
#include <fstream>
#define NMAX 1001
using namespace std;
ifstream f("val.in");
int n;
bool D[NMAX][NMAX];
void ReadData()
{f>>n;
 for(int i=1;i<=n;++i)
  for(int j=1;j<=n;++j)f>>D[i][j];
}
bitset<NMAX>Viz[NMAX];
inline bool Cond(int x,int y)
{return (x<=n&&y<=n&&x>=1&&y>=1&&D[x][y]&&!Viz[x][y]);
}
int maxi;
const short dx[]={-1,1,0,0};
const short dy[]={0,0,-1,1};
int lengharea;
void FILL(int k,int x,int y)
{Viz[x][y]=1;
 lengharea++;
 for(int ord=0;ord<4;++ord)
  {int xx=x+dx[ord];
   int yy=y+dy[ord];
   if(Cond(xx,yy))FILL(k+1,xx,yy);
  }
}
void Solve()
{for(int i=1;i<=n;++i)
  for(int j=1;j<=n;++j,lengharea=0)
      if(!Viz[i][j]&&D[i][j])FILL(1,i,j),maxi=max(lengharea,maxi);
 cout<<maxi;
}
int main()
{ReadData();
 Solve();
    return 0;
}
