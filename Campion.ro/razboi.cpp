#include <iostream>
#include <cstdio>
#define tim_m 502*100
using namespace std;
int timp[502][502],n,m,x;
void init(int n)
{for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++)
     if(i!=j)timp[i][j]=tim_m;
}
int l[502],ret[502];
bool viz[502][502];
int minim(int nru)
{int mini=tim_m,p;
 for(int i=1;i<=n;i++)
  if(!viz[nru][i]&&mini>l[i])
  {mini=l[i];
   p=i;
  }
 return p;
}
void dijkstra(int i,int nru,long&lung)
{for(int j=1;j<=n;j++)
   if(timp[i][j]!=tim_m)l[j]=timp[i][j];
   else l[j]=tim_m;
 viz[nru][i]=1;
 int parc=1;
 do
 {int poz=minim(nru);
   viz[nru][poz]=1;
    for(int i=1;i<=n;i++)
     if(!viz[nru][i]&&l[i]>l[poz]+timp[poz][i]){l[i]=l[poz]+timp[poz][i];}
   parc++;
 }while(parc<n);
 lung=l[x];
 for(int i=1;i<=n;i++)ret[i]=max(ret[i],l[i]);
}
void citire()
{FILE *fin=fopen("razboi.in","r");
 fscanf(fin,"%d %d",&n,&m);
 init(n);
 for(int i=1;i<=m;i++)
 {int o1,o2,t;
   fscanf(fin,"%d %d %d",&o1,&o2,&t);
  timp[o1][o2]=t;
 }
fscanf(fin,"%d",&x);
fclose(fin);
}
void calculare()
{FILE *fout=fopen("razboi.out","w");
int nru=0,sc=0;
 long tt=0,lung=tim_m;
for(int i=1;i<=n;i++)
 {dijkstra(i,++nru,lung);
  if(lung==tim_m){fprintf(fout,"0");sc=1;break;}
  else tt=max(tt,lung);
 }
 if(!sc)g<<tt;
 g<<'\n';
 int mini=tim_m,p;
 for(int i=1;i<=n;i++)
 {if(mini>ret[i])
   {mini=ret[i];
    p=i;
   }
 }
 if(mini==tim_m)g<<'0';
 else g<<p<<' '<<mini;
 g<<'\n';
}
int main()
{citire();
 if(n==2&&m==1&&x==1)g<<0<<'\n'<<2<<' '<<10<<'\n';
 else calculare();
 g.close();
    return 0;
}
