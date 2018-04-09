#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
ifstream f("linie.in");
ofstream g("linie.out");
long sum[14][14],n,st;
void citire()
{f>>n;
 int val;
 for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++)
  {f>>val;
   st+=val;
   sum[i][j]=val+sum[i][j-1];
  }
}
int sol[15],x[15],difm=40000,ss,sd;
double modul(double val)
{return abs(val);}
void comb(int k)
{long s=0;
 for(int i=1;i<=k;i++)s+=sum[i][x[i]];
 if(difm>modul(s-(st-s)))
 {ss=s;
  for(int i=1;i<=n;i++)sol[i]=x[i];
  difm=modul(s-(st-s));
 }
}

void back(int k,int j)
{if(k==1)
  for(int i=0;i<=n;i++)
  {x[k]=i;
   if(k==n)comb(k);
   else back(k+1,i-1);
  }
 else
 {int p=j;
  if(j<0)p+=2;
  for(int i=p;i<=j+2&&i<=n;i++)
  {x[k]=i;
   if(k==n)comb(k);
   else back(k+1,i-1);
  }
 }
}
int main()
{citire();
 back(1,0);
 sd=st-ss;
 g<<ss<<'\n'<<sd<<'\n';
 for(int i=1;i<=n;i++)g<<sol[i]<<' ';
    return 0;
}
