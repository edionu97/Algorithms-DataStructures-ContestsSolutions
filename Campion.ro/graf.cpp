#include <iostream>
#include <fstream>
using namespace std;
ifstream f("graf.in");
ofstream g("graf.out");
struct muchie
{short x,y;
}v[14001];
struct mat
{int vv[7501];
}pp[7501];
short m,n,a,b;
void citire()
{f>>n>>m>>a>>b;
 for(int i=1;i<=m;i++)f>>v[i].x>>v[i].y;
}
bool gasit(short v1,short v2)
{for(int i=1;i<=m;i++)
  if(v[i].x==v1&&v[i].y==v2||v[i].x==v2&&v[i].y==v1)return 1;
 return 0;
}
long l1[7501],l2[7501],c[7501],d[7501];
bool ut1[7501],ut2[7501];
void bfsx(short a,short b)
{l1[a]=0;
 c[1]=a;
 ut1[a]=1;
 short inc=1,sf=1;
 while(inc<=sf)
 {for(int i=1;i<=n;i++)
   if(!ut1[i]&&gasit(c[inc],i))
    {l1[i]=l1[c[inc]]+1;
     ut1[i]=1;
     c[++sf]=i;
    }
    inc++;
 }
}
void bfsy(short a,short b,short&sf)
{l2[b]=0;
 c[1]=b;
 ut2[b]=1;
 short inc=1;
 while(inc<=sf)
 {for(int i=1;i<=n;i++)
   if(!ut2[i]&&gasit(c[inc],i))
    {l2[i]=l2[c[inc]]+1;
     ut2[i]=1;
     c[++sf]=i;
    }
    inc++;
 }
}
int fol[7501];
bool sc[7501];
void calc()
{short sf=1,dims=0,nr=0;;
 bfsx(a,b);
 bfsy(a,b,sf);
 for(int i=1;i<=sf;i++)
 if(l1[c[i]]+l2[c[i]]==l1[b])
 {sc[c[i]]=1;
  fol[l1[c[i]]]++;
 }
 for(int i=1;i<=sf;i++)
    if(fol[l1[c[i]]]==1&&sc[c[i]])dims++;
    g<<dims<<'\n';
  for(int i=1;i<=n;i++)
    if(fol[l1[i]]==1&&sc[i])g<<i<<' ';
}
int main()
{citire();
 calc();
 //cout<<sizeof(pp);
    return 0;
}
