#include <iostream>
#include <algorithm>
#include <cstdio>
#define lengh 50001
using namespace std;
long a[lengh],b[lengh],n,m;
void citire()
{freopen("unudoi.in","r",stdin);
 freopen("unudoi.out","w",stdout);
 scanf("%d%d",&n,&m);
 for(int i=1;i<=m;i++)scanf("%d",&a[i]);
 for(int j=1;j<=n;j++)scanf("%d",&b[j]);
}
inline bool cresc(long x,long y)
{return x<y;
}
 void sortare(int m,int n)
{sort(a+1,a+m+1,cresc);
 sort(b+1,b+n+1,cresc);
}
int poz[lengh];
 void rezolvare(int m,int n)
{sortare(m,n);
 for(int i=1;i<=n;i++)
  if(a[1]<=b[i])
   {poz[1]=i;
    break;
   }
 for(int i=2;i<=m;i++)
 {int p=poz[i-1];
  if(a[i]<=b[p])poz[i]=p;
  else
   for(int j=poz[i-1];j<=n;j++)
    if(a[i]<=b[j])
    {poz[i]=j;
     break;
    }

 }
}
void calcul(int n,int m)
{int nr=0;
 for(int i=1;i<=m;i++)
 {nr++;
  while(poz[i]==poz[i+1]&&i+1<=m)i++;
 }
 printf("%d",nr);
}
int main()
{citire();
 rezolvare(m,n);
 calcul(n,m);
    return 0;
}
