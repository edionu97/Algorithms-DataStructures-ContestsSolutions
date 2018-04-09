#include <iostream>
#include <fstream>
using namespace std;
ifstream f("xor1.in");
ofstream g("xor1.out");
long long v[2001],n,xt;
void citire()
{f>>n;
 for(short i=1;i<=n;i++){f>>v[i];xt=xt xor v[i];}
}
long rez(long long v[2001])
{bool ok=1;
 short k=1,p=2;
 long long x1=0,x2,x3,maxi=0;
 do
 {if(ok==1)
  {x1=x1 xor v[k];
   x2=x3=0;
  }
  x2=x2 xor v[p];
  x3=xt xor x2 xor x1;
  if(x1+x2+x3>maxi)maxi=x1+x2+x3;
  if(p==n-1)
  {k++;
   p=k;
   ok=1;
  }
  else ok =0;
  p++;
 }while(k<n-1);
 return maxi;
}
int main()
{citire();
 g<<rez(v);
     return 0;
}
