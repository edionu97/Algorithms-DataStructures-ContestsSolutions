#include <iostream>
#include <fstream>
#include <algorithm>
#include <ctime>
using namespace std;
ifstream f("vintage.in");
ofstream g("vintage.out");
struct dat
{long long val;
 long long cost;
 int poz;
}v[1001];
struct ad
{long long val;
 long long cost;
 int poz;
}x[1001];
int n,k,y[1001];
void citire()
{f>>n>>k;
 for(int i=1;i<=n;i++)
 {f>>v[i].cost>>v[i].val;
  x[i].cost=v[i].cost;
  x[i].val=v[i].val;
  v[i].poz=i;
 }
}
int poz(int i,int j)
{bool ok=0;
 dat aux;
 while(i<j)
 {if(v[i].val<v[j].val)
  {aux=v[i];
   v[i]=v[j];
   v[j]=aux;
   if(ok)ok=0;
   else ok=1;
  }
  if(ok)j--;
  else i++;
 }
 return i;
}
void divmp(int i,int j)
{if(i<j)
  {int p=poz(i,j);
   divmp(i,p-1);
   divmp(p+1,j);
  }
}
void rezolv(int n)
{long long p,s=0,i;
 for(i=1;i<=k;i++)s+=v[i].val,y[i]=v[i].poz;
 i--;
 g<<s<<' ';
 s=0;
 for(int j=1;j<k;j++)s=s+x[y[j]].cost;
 p=x[v[i].poz].cost;
  y[k]=v[i].poz;
 while(v[i].val==v[i+1].val&&i+1<=n)
 {i++;
  int aux=p;
  p=min(p,x[v[i].poz].cost);
  if(p<aux)y[k]=v[i].poz;
 }
s+=p;
g<<s<<'\n';
for(int i=1;i<=k;i++)g<<y[i]<<' ';
}
int main()
{citire();
 divmp(1,n);
 rezolv(n);

    return 0;
}
