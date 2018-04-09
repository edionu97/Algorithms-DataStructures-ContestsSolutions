#include <iostream>
#include <fstream>
using namespace std;
ifstream f("vanatoare.in");
ofstream g("vanatoare.out");
long ka,kb,i;
void citire()
{f>>ka>>kb;}
long v[100000];
void formare(long v[100000],long ka,long kb,long&i)
{int ok=1,s=3;
 v[1]=1;
 v[2]=2;
 i=2;
 while(ok)
 {i++;
  v[i]=v[i-1]+v[i-2];
  s=s+v[i];
  if(s>(ka+kb))
  {i--;
   break;
  }
 }
}
void vanatoare(long v[100000])
{long nra,nrb,ok,nr=0,n=i,j;
 i=0;
 do
 {i++;
  nra=nrb=0;
  ok=1;
  for(j=1;j<=v[i];j++)
   if(ok)
   {nra++;
    ok=0;
   }
   else
   {nrb++;
    ok=1;
   }
  if(ka>nra)ka=ka-nra;
  else break;
  if(kb>nrb)kb=kb-nrb;
   else break;
   nr++;
 }while(i<=n);
 g<<nr<<endl;
 g<<ka<<endl;
 g<<kb<<endl;
}
int main()
{citire();
 formare(v,ka,kb,i);
 vanatoare(v);
    return 0;
}
