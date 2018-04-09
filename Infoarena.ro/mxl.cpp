#include <iostream>
#include <cstring>
#include <fstream>
#define lengh 40*40+1
#include <cstdlib>
using namespace std;
ifstream f("mxl.in");
ofstream g("mxl.out");
struct form
{short li,col,nre;
 char v[260];
}x[lengh];
long long  n,k,b[41][41];
void citire()
{f>>n>>k;
 for(int i=1;i<=k;i++)
 {f>>x[i].li>>x[i].col;
  f.get();
  f.get(x[i].v,260);
  x[i].nre=strlen(x[i].v);
 }
}
struct numeric
{short col[256],lin[256],nr,suma;
}y[256];
void sep(int i)
{char *p,c=':';
 char a[256][256];
 int sum=0,j=0;
 p=strtok(x[i].v,"+=");
 while(p)
 {strcpy(a[++j],p);
  p=strtok(NULL,"+=");
 }
 int elem=1,k=i;
 for(int i=1;i<=j;i++)
 if(!strchr(a[i],c))sum+=atoi(a[i]);
 else
 {p=strtok(a[i],":");
  y[k].lin[elem]=atoi(p);
  p=strtok(NULL,":");
  y[k].col[elem++]=atoi(p);
 }
 y[k].nr=elem-1;
 y[k].suma=sum;
}
bool fol[lengh-1][lengh-1];
bool verif(int i)
{for(int j=1;j<=y[i].nr;j++)
 if(!fol[y[i].lin[j]][y[i].col[j]])return 0;
 return 1;
}
void sepa(int k)
{for(int i=1;i<=k;i++)sep(i);
 bool ok;
do
{ok=0;
  for(int i=1;i<=k;i++)
  if(verif(i)&&!fol[x[i].li][x[i].col])
  {long long  sum=0;
   for(int j=1;j<=y[i].nr;j++)sum+=b[y[i].lin[j]][y[i].col[j]];
   b[x[i].li][x[i].col]=y[i].suma+sum;
   fol[x[i].li][x[i].col]=1;
    ok=1;
  }
}while(ok);
 for(int i=1;i<=n;i++)
 {for(int j=1;j<=n;j++)
   g<<b[i][j]<<' ';
   g<<'\n';}
}
int main()
{citire();
 sepa(k);
 return 0;
}