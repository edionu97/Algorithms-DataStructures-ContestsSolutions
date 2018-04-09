#include <fstream>
#define maxn 56000
using namespace std;
ifstream f("jeton.in");
ofstream g("jeton.out");
unsigned v[maxn],x[maxn],a,p[maxn],pm,pmin;
short m,n;
void citire()
{f>>n>>m;
 pm=0,pmin=65000;
 for(int i=1;i<=n+m;i++)
 {f>>a;
  if(i<=n)
  {v[i]=a;
   p[v[i]]=1;
  }
  else
  {x[i-n]=a;
   if(p[x[i-n]]==1)
    {if(x[i-n]>pm)pm=x[i-n];
     if(x[i-n]<pmin)pmin=x[i-n];
    }
  }
}
g<<pmin<<" "<<pm<<" ";
}
void winner(unsigned pm,unsigned pmin)
{int i,nr1=0,nr2=0,s;
for(i=1;i<=n;i++)
 if(v[i]<pmin||v[i]>pm)nr1++;
for(i=1;i<=m;i++)if(x[i]<pmin||x[i]>pm)nr2++;
if(nr1==nr2)g<<0;
if(nr1>nr2)g<<1;
if(nr2>nr1)g<<2;
}
int main()
{citire();
 winner(pm,pmin);
    return 0;
}
