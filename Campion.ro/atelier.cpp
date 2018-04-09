#include <iostream>
#include <fstream>
using namespace std;
ifstream f("atelier.in");
ofstream g("atelier.out");
long long sa[10001],sb[10001],suma,sumb,maxi,nrz;
short a[10001],b[10001],n;
char M;
void citire()
{f>>n;
 for(int i=1;i<=n;i++)
 {f>>a[i]>>b[i];
  suma+=a[i];
  sumb+=b[i];
  sa[i]=a[i]+sa[i-1];
  sb[i]=b[i]+sb[i-1];
 }
}
void calcul1(int n)
{long long sum,ef=0;
 for(int i=2;i<=n;i++)
  {sum=0;
   ef++;
   sum=sa[i-1]+(sumb-sb[i-1]);
   if(sum>=maxi)
   {maxi=sum;
    nrz=ef;
    M='A';
   }
  }
}
void calcul2(int n)
{long long sum,ef=0;
 for(int i=2;i<=n;i++)
 {sum=0;
  ef++;
  sum=sb[i-1]+(suma-sa[i-1]);
   if(sum>maxi)
   {maxi=sum;
    nrz=ef;
    M='B';
   }
 }
}
int main()
{citire();
 calcul1(n);
 calcul2(n);
 g<<maxi<<'\n'<<M<<'\n';
 g<<nrz<<'\n';
    return 0;
}
