#include <iostream>
#include <fstream>
using namespace std;
ifstream f("munte3.in");
ofstream g("munte3.out");
long v[101],n,nrs,x[101],y[100000];
void citire()
{f>>n;
 for(int i=1;i<=n;i++)f>>x[i],v[i]=x[i];
}
void cop(int&m)
{for(int i=1;i<=n;i++)
 if(y[x[i]]!=1)v[++m]=x[i];
}
void rez(int n)
{int ok=0,nr1,ok1,nr2,m,p,cont=1,aux;
m=n;
do
{ok=0;
  for(int i=1;i<=m;i++)
   {ok1=0,nr1=1,nr2=0;
     while(v[i]<v[i+1]&&i+1<=m)
      {i++;
       nr1++;
       ok1=1;
      }
      p=i;
    if(ok1)
    {while(v[i]>v[i+1]&&i+1<=m)
      {i++;
       nr2++;
      }
     if(nr1>1&&nr2&&nr1+nr2>=3)
     {ok=1;
      y[v[p]]=1;
      nrs++;
      i--;
     }
    }
   }
   if(cont==1){aux=nrs;g<<nrs<<'\n';}
   cont++;
   if(ok)
   {m=0;
   cop(m);
   }
}while(ok);
g<<nrs<<'\n';
g<<m;
}
int main()
{citire();
 rez(n);

    return 0;
}
