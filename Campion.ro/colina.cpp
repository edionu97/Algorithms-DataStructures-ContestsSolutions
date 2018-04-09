#include <iostream>
#include <fstream>
#include <cstdio>
#define MAXN 100001
using namespace std;
int n,m,v[MAXN];
int poz;
int binsearch1(int x)
{int st=1,dr=poz-1,mij;
 while(st<=dr)
 {mij=(st+dr)/2;
  if(v[mij]==x)return mij;
  else
   if(v[mij]<x)st=mij+1;
   else dr=mij-1;
 }
 return 0;
}

int binsearch2(int x)
{int st=poz,dr=n;
 while(st<=dr)
 {int mij=(st+dr)/2;
  if(v[mij]==x)return mij;
  else
   if(v[mij]>x)st=mij+1;
   else dr=mij-1;
 }
 return 0;
}

void citire()
{freopen("colina.in","r",stdin);
 freopen("colina.out","w",stdout);
 scanf("%d%d",&n,&m);
 int i;
 for(i=1;i<=n;i++)
 {scanf("%d",&v[i]);
  if(v[i]<v[i-1]&&!poz)poz=i;
 }
 int x,b1=0,b2=0;
 for(i=1;i<=m;i++)
 {scanf("%d",&x);
  b1=binsearch1(x);
  b2=binsearch2(x);
  if(b1||b2)
  {printf("DA ");
    if(b1)printf("%d ",b1);
    if(b2)printf("%d",b2);
    printf("\n");
  }
else
  printf("NU\n");
 }

}
int main()
{citire();
    return 0;
}
