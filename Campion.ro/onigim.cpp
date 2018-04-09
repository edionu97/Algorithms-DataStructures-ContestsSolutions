#include <iostream>
#include <fstream>
#include <algorithm>
#define lengh 1001
using namespace std;
ifstream f("onigim.in");
ofstream g("onigim.out");
short n,p[lengh],a[lengh],k,b[lengh],A,B,C;
void citire()
{f>>n>>k;
 for(int i=1;i<=k;i++)f>>p[i];
 for(int i=1;i<=n;i++){f>>a[i];b[i]=a[i];}
}
bool dcresc(short c,short d)
{return c>d;}
void sortare()
{sort(a+1,a+n+1,dcresc);}
int v[lengh ],x[lengh ];
void ad(short a[lengh ])
{int j=k,i=1;
 while(j>=1&&i<=n)
 {if(v[a[i]]==0)v[a[i]]=p[j--];
  i++;
 }
}
void verif(int nr)
{if(nr==p[k])A++;
 else if(nr==p[k-1])B++;
 else if(nr==p[k-2])C++;
}
void afisare(int n)
{short maxi=0;
 sortare();
 ad(a);
 for(int i=1;i<=n;i++)
 {g<<v[b[i]]<<' ';
  verif(v[b[i]]);
  x[v[b[i]]]++;
  if(x[v[b[i]]]>maxi)maxi=x[v[b[i]]];
 }
 g<<'\n';
 g<<A+B+C;
 g<<'\n';
 g<<maxi;

}
int main()
{citire();
 afisare(n);
    return 0;
}
