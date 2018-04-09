#include <iostream>
#include <fstream>
#include <cstdio>
#define lengh 1000001
using namespace std;
short v[lengh],sc[lengh];
int x[1001],y[1001],n,mm,m;
void rez(int m)
{for(int i=1;i<=m;i++)
 if(v[y[i]])
 {short nre=1;
  while(y[i]==y[i+1]&&i+1<=m)
  {i++;
   nre++;
  }
  if(v[y[i]]>nre)v[y[i]]=nre;
  sc[y[i]]++;
 }
}
void citire()
{freopen("ausoara.in","r",stdin);
 freopen("ausoara.out","w",stdout);
 scanf("%d%d",&n,&mm);
 for(int i=1;i<=mm;i++)
 {scanf("%d",&x[i]);
  v[x[i]]++;
 }
 for(int i=1;i<n;i++)
 {scanf("%d",&m);
  for(int i=1;i<=m;i++)scanf("%d",&y[i]);
  rez(m);
 }
}
void calcul()
{short dim=0;
 for(int i=1;i<=mm;i++)
 if(sc[x[i]]==n-1)
 {dim+=v[x[i]];
  while(x[i]==x[i+1]&&i<mm)i++;
 }
 printf("%d ",dim);
  for(int i=1;i<=mm;i++)
   if(sc[x[i]]==n-1)
     while(v[x[i]])
     {printf("%d ",x[i]);
      v[x[i]]--;
     }
}
int main()
{citire();
 calcul();
    return 0;
}
