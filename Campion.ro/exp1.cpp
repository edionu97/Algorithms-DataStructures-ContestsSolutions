#include <iostream>
#include <fstream>
#define lengh 30001
using namespace std;
ifstream f("exp1.in");
ofstream g("exp1.out");
int m,n,v[lengh],p[lengh],maxi;
bool fol[lengh];
void citire()
{f>>m>>n;
 for(int i=1;i<=n;i++)f>>v[i];
}
bool prim(int x)
{for(int i=2;i<=x/2;i++)
  if(x%i==0)return 0;
  return 1;
}
void fact_primi(int val)
{int d=2;
 do
 {if(prim(d))
  while(val%d==0)
  {p[d]++;
   val/=d;
  }
  if(p[d]){fol[d]=1;maxi=max(maxi,d);}
  d++;
 }while(val>1);
}
void numere(int n)
{for(int i=1;i<=n;i++)fact_primi(v[i]);}
bool verif(int n)
{for(int i=1;i<=maxi;i++)
  if(p[i]%m&&fol[i])return 0;
 return 1;
}
void afis(int n)
{bool ok=verif(n);
 g<<ok<<'\n';
 if(ok)
 for(int i=2;i<=maxi;i++)
     if(fol[i])g<<i<<' '<<p[i]/m<<'\n';
}
int main()
{citire();
 numere(n);
 afis(n);


    return 0;
}
