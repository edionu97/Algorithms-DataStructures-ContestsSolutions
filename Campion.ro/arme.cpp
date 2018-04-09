#include <fstream>
#include <algorithm>
using namespace std;
ifstream f("arme.in");
ofstream g("arme.out");
short v[1002],n,m,x[1002];
void citire()
{f>>n>>m;
 for(short i=1;i<=n;i++)f>>v[i];
 for(short i=1;i<=m;i++)f>>x[i];
}
bool cresc(short a,short b)
{return a<b;}
bool dcresc(short a,short b)
{return a>b;}
void sortare(short x[1002],short v[1002])
{sort(v+1,v+n+1,cresc);
 sort(x+1,x+m+1,dcresc);
}
void s_max(short x[1002],short v[1002])
{sortare(x,v);
 long long smax=0;
 for(short i=1;i<=n;i++)
  if(v[i]<x[i])smax+=x[i];
  else smax+=v[i];
  g<<smax;
}
int main()
{citire();
 s_max(x,v);
    return 0;
}
