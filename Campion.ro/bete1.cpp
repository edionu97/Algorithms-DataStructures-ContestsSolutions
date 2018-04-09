#include <fstream>
#include <algorithm>
#include <iostream>
using namespace std;
ifstream f("bete1.in");
ofstream g("bete1.out");
int n,v[10001],i;
void citire(int&n,int v[10001])
{int i;
 f>>n;
 for(i=1;i<=n*2;i++)f>>v[i];
}
bool cresc(int a,int b)
{return a<b;}
bool descr(int c,int d)
{return c>d;}
void solve1(int v[10001])
{sort(v+1,v+n+1,cresc);
 sort(v+n+1,v+2*n+1,descr);
 g<<v[1]+v[n+1]<<'\n';
}
int j,nr,x,p[10001],im[10001],y;
int a;
void prelucrare2(int n,int v[10001])
{sort(v+1,v+n+1,descr);
 sort(v+n+1,v+2*n+1,descr);
 a=v[n+1]+v[1];
 g<<a;
 x=2;
 y=n+2;
 nr=1;
 do
 {if(v[x]+v[y]==a)nr++;
  x++;
  y++;
 }while(x<=n && y<=2*n);
 g<<endl;
 g<<nr;
}
int main()
{citire(n,v);
 solve1(v);
 prelucrare2(n,v);
 return 0;
}
