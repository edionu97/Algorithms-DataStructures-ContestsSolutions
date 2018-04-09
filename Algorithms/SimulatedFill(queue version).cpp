#include <iostream>
#include <utility>
#include <fstream>
#include <bitset>
#include <queue>
#define x first
#define y second
#define NMAX 1001
using namespace std;
ifstream f("val.in");
queue< pair<int,int> > Q;
int n;
bool D[NMAX][NMAX];
void ReadData()
{f>>n;
 for(int i=1;i<=n;++i)
  for(int j=1;j<=n;++j)f>>D[i][j];
}
bitset<NMAX>Viz[NMAX];
inline bool Cond(int x,int y)
{return (x>=1&&y>=1&&x<=n&&y<=n&&D[x][y]&&!Viz[x][y]);
}
const short dx[]={-1,1,0,0};
const short dy[]={0,0,-1,1};
int lengharea;
void SimulateFill(int x,int y)
{Q.push(make_pair(x,y));
 Viz[x][y]=true;
 pair<int,int>Lc;
 while(!Q.empty())
 {++lengharea;
  Lc=Q.front();
   for(int ord=0;ord<4;++ord)
      {int xx=Lc.x+dx[ord];
       int yy=Lc.y+dy[ord];
       if(Cond(xx,yy))Q.push(make_pair(xx,yy)),Viz[xx][yy]=true;
      }
  Q.pop();
 }
}
int maxi;
void Solve()
{for(int i=1;i<=n;++i)
  for(int j=1;j<=n;++j,lengharea=0)
     if(D[i][j]&&!Viz[i][j])SimulateFill(i,j),maxi=max(lengharea,maxi);
 cout<<maxi;
}
int main()
{ReadData();
Solve();
return 0;
}
