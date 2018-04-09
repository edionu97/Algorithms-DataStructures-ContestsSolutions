#include <fstream>
#include <cstring>
#define maxn 100000
using namespace std;
ifstream f("compar.in");
ofstream g("compar.out");
char v[maxn];
bool ok;
long p[maxn],n,x[maxn];
void citire()
{f.get(v,maxn-1);
 n=strlen(v);
}
void afisare(long k)
{g<<n+1<<endl;
 for(long i=1;i<=k;i++)g<<x[i]<<" ";
}
short valid(long k ,long d)
{if(v[k-1]=='>')
  {for(long i=1;i<d;i++)
    if(d>i&&p[i]==0)return 1;
  }
 else
  if(v[k-1]=='<')
   for(long i=d+1;i<=n;i++)
     if(d<i&&p[i]==0)return 1;
 return 0;
}
short validare(long k,long p,long d)
{if(v[k-2]=='>'&&p<d)return 1;
 if(v[k-2]=='<'&&p>d)return 1;
 return 0;
}
void back(long k)
{for(long i=1;i<=n+1&&!ok;i++)
 {x[k]=i;
  if(p[x[k]]==0)
   if(k==1&&valid(k,x[k]))
    {p[x[k]]=1;
     back(k+1);
    }
   else
   if(k>1)
    if(k==n+1){afisare(k);ok=1;}
    else
    if(valid(k,x[k]))
     if(validare(k,x[k],x[k-1]))
      {p[x[k]]=1;
       back(k+1);
      }
     else break;
 }
p[x[k-1]]=0;
}
int main()
{citire();
 back(1);
 return 0;
}
