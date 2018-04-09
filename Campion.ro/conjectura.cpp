#include <iostream>
#include <fstream>
#define size_tt 60000
using namespace std;
ifstream f("conjectura.in");
ofstream g("conjectura.out");
short v[size_tt],c[size_tt],n;
bool ok(int p,short v[size_tt],short c[size_tt])
{int dim=size_tt-1;
 for(int i=p;i<size_tt;i++)
  if(v[i]!=c[dim--])return 0;
  return 1;
}
void adun(int nr)
{int p=size_tt;
 while(nr)
 {v[--p]=nr%10;
  c[p]=v[p];
  nr/=10;
 }
 int nrm=0,t=0;
 if(ok(p,v,c))g<<0<<'\n';
 else
{while(nrm!=1000)
{t=0;
for(int i=size_tt-1;i>=p;i--)
{v[i]+=c[size_tt-1-i+p]+t;
 t=v[i]/10;
 v[i]=v[i]%10;
}
if(t)v[--p]=t;
for(int i=p;i<=size_tt-1;i++)c[i]=v[i];
nrm++;
if(ok(p,v,c))
{g<<nrm<<'\n';
 break;
}
}
if(nrm==1000)g<<"LYCHREL"<<'\n';
}
}
void calcul()
{f>>n;
 for(int i=1;i<=n;i++)
 {int x;
  f>>x;
   adun(x);
 }
}
int main()
{calcul();
    return 0;
}
