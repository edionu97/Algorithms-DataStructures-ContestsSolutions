#include <iostream>
#include <fstream>
#define max_s 50001
using namespace std;
ifstream f("secvb.in");
ofstream g("secvb.out");
int n;
int nrt[max_s];
int nrbit(int x)
{int nr=0;
 while(x)
 {if(x%2!=0)nr++;
  x/=2;
 }
 return nr;
}
int x,T;
void citire()
{f>>n>>T;
 for(int i=1;i<=n;i++)
 {f>>x;
  nrt[i]=nrbit(x)+nrt[i-1];
 }
}
void solve(int n)
{int nr=0;
 for(int i=1;i<=n;i++)
{int nrs=nrt[i-1],j=i+1;
  if((nrt[i]-nrs)==T)nr++;
 while((nrt[j]-nrs)<T&&j<=n)j++;
  if((nrt[j]-nrs)==T)nr++;
}
 g<<nr;
}
int main()
{citire();
 solve(n);
    return 0;
}
