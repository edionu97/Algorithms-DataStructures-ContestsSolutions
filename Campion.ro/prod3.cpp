#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;
int v[8],x[8],n,nrn,nrp;
void rez1(int&nrn,int val,int x[8])
{if(val>x[6])
 {int p=6;
  while(p&&x[p]<val)p--;
  for(int i=nrn+1;i>p+1;i--)x[i]=x[i-1];
  x[p+1]=val;
  nrn++;
 }
 nrn=min(nrn,6);
}
void rez2(int val,int x[8])
{if(val>x[3])
 {x[3]=val;
  if(x[3]>x[2])swap(x[3],x[2]);
  if(x[2]>x[1])swap(x[2],x[1]);
 }
 else
  if(val<x[4])
 {x[4]=val;
  if(x[4]<x[5])swap(x[4],x[5]);
  if(x[5]<x[6])swap(x[5],x[6]);
 }
}
void citire()
{freopen("prod3.in","r",stdin);
 freopen("prod3.out","w",stdout);
 scanf("%d",&n);
 int val;
 for(int i=1;i<=7;i++)v[i]=x[i]=-30001;
 for(int i=1;i<=n;i++)
 {scanf("%d",&val);
  if(val<0)
   if(nrn!=6)rez1(nrn,val,x);
   else rez2(val,x);
   else
   if(nrp!=6)rez1(nrp,val,v);
   else rez2(val,v);

 }
}
void Solve(int nrn,int nrp)
{int p=-4000000,a,b,c;
 if(nrp>=3)
  if(v[1]*v[2]*v[3]>p)
  {a=v[3],b=v[2],c=v[1];
   p=v[1]*v[2]*v[3];
  }
 if(nrp>=2&&nrn>=1)
  if(v[nrp-1]*v[nrp]*x[1]>p)
   {a=x[1],b=v[nrp-1],c=v[nrp];
    p=v[nrp-1]*v[nrp]*x[1];
   }
 if(nrp>=1&&nrn>=2)
  if(v[1]*x[nrn]*x[nrn-1]>p)
  {a=x[nrn],b=x[nrn-1],c=v[1];
   p=v[1]*x[nrn]*x[nrn-1];
  }
 if(nrn>=3)
  if(x[1]*x[2]*x[3]>p)
  {a=x[3],b=x[2],c=x[1];
   p=x[1]*x[2]*x[3];
  }
 printf("%d %d %d",a,b,c);
}
int main()
{citire();
Solve(nrn,nrp);
    return 0;
}
