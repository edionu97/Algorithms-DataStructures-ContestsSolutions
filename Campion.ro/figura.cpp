#include <fstream>
using namespace std;
ifstream f("figura.in");
ofstream g("figura.out");
short v[20][20],d,n;
void citire()
{f>>d>>n;
 short a,b;
 for(short i=1;i<=n;i++)
 {f>>a>>b;
  v[a][b]=1;
 }
}
short nr(short i,short j)
{short o=0;
 if(v[i-1][j]==0)o++;
 if(v[i+1][j]==0)o++;
 if(v[i][j-1]==0)o++;
 if(v[i][j+1]==0)o++;
 return o;
}
void perim(short v[20][20])
{short p=0;
 for(short i=1;i<=d;i++)
 for(short j=1;j<=d;j++)
  if(v[i][j]==1)p+=nr(i,j);
 g<<p;
}
int main()
{citire();
 perim(v);
 return 0;
}
