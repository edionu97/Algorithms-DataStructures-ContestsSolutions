#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream f("grupe1.in");
ofstream g("grupe1.out");
char v[201];
int n,k,mini=32000,maxi,x[200],a;
void solve(int a,int x[200],bool&ok)
{int nrf=0,nrb=0;
 for(int i=1;i<=a;i++)
  if(v[x[i]-1]=='f')nrf++;
  else nrb++;
 if(nrb>nrf&&nrb-nrf>1)ok=0;
 if(nrf>nrb&&nrf-nrb>1)ok=0;
 g<<nrb<<' '<<nrf<<'\n';
}
void citire()
{f>>n>>k;
 f.get();
 f.get(v,201);
 bool ok=1;
 for(int i=1;i<=k;i++)
 {f>>a;
  if(a>maxi)maxi=a;
  if(a<mini)mini=a;
  for(int j=1;j<=a;j++)f>>x[j];
  solve(a,x,ok);
 }
 if(ok==1&&maxi-mini<=1)g<<"DA";
 else g<<"NU";
}
int main()
{citire();
 return 0;
}
