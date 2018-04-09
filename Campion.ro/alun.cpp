#include <iostream>
#include <fstream>
using namespace std;
ifstream f("alun.in");
ofstream g("alun.out");
long long d,n1,n2,x,y,nr,k;
long long val(long long p)
{if(p==n1)return n2;
 return n1;
}
void rez1(long long  n1,long long  n2)
{int j=4;
 d=n1;
 nr=n1;
 while(j<=x)
 {if(j%2==0)
  {d=val(d);
   nr+=d;
  }
  j+=2;
 }
g<<nr-x/k<<'\n';
}
void solv(long long y)
{rez1(n1,n2);
 long long s=0,nr=2;
 int j=3;
 d=n1;
 s=d;
 while(s!=y&&s<y)
 {if(j%2!=0)nr++;
  else
  {d=val(d);
   s+=d;
   nr++;
  }
  j++;
 }
g<<nr;
}
int main()
{f>>n1>>n2>>x>>k>>y;
 solv(y);
    return 0;
}
