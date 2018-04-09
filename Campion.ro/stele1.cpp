#include <fstream>
#define lengh 60001
using namespace std;
ifstream f("stele1.in");
ofstream g("stele1.out");
long long v[lengh],n,k,p=1;
void citire()
{f>>k>>n;
 v[1]=1;
 v[2]=3;
 for(long long i=3;i<=k;i++)v[i]=v[i-1]+i+p++;
 g<<v[k]<<'\n';
}
void linie_col(long long v[lengh])
{long long i=2,ls,li,p=0,nr=1;
 bool ok=1;
 v[1]=1;
 while(ok)
 {v[i]=v[i-1]+i+p++;
  li=v[i]+(i-1);
  ls=v[i]-(i-1);
  if(n<=li&&n>=ls)
  {ok=0;
   g<<i<<' ';
  }
  else i++;
 }
 li=v[i]+(i-1);
 ls=v[i]-(i-1);
 for(i=li;i>=ls;i--)
  if(i==n)
  {g<<nr;
   break;
  }
  else nr++;
}
int  main()
{citire();
 linie_col(v);
 return 0;
}
