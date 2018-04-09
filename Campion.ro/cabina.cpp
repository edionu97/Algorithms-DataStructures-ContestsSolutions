#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cabina.in");
ofstream g("cabina.out");
short v[41],pers,cost,a,n,nr;
void citire()
{f>>n;
 for(short i=1;i<=n;i++)
 {f>>v[i];
  f>>a;
  if(i<n)pers+=a;
 }
 g<<pers<<'\n';
}
void combus(short v[41])
{for(short i=1;i<n;i++)
 if(v[i+1]-v[i]>0)cost+=(v[i+1]-v[i])*3;
 else cost+=(v[i+1]-v[i])*(-1);
 g<<cost<<'\n';
}
void statii(short v[41])
{for(short i=2;i<n;i++)
  if(v[i]>v[i-1]&&v[i]>v[i+1])nr++;
  else
  if(v[i]<v[i-1]&&v[i]<v[i+1])nr++;
 g<<nr;
}
int main()
{citire();
 combus(v);
 statii(v);
    return 0;
}
