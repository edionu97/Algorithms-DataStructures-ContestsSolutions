#include <fstream>
#include <iostream>
#define mod 100003
using namespace std;
ifstream f("2sah.in");
ofstream g("2sah.out");
int t,n,k;
long long exp_log(long long a,long long exp)
{if(exp==0)return 1;
 else
 {if(exp%2==0)return exp_log((a*a)%mod,exp/2);
  if(exp%2!=0)return (a*exp_log((a*a)%mod,exp/2))%mod;
 }
}
inline int getnumber(int k)
{int a=1,b=1,c=2;
 if(k==n)return b;
 if(k==n-1)return c;
 for(int i=n-2;i>=k;--i)
 {int aux=c;
  c=(a+b+c)%mod;
  a=b;
  b=aux;
 }
 return c;
}
int main()
{f>>t>>n>>k;
 if(t==1)g<<exp_log(3,k-1)<<'\n';
 else g<<getnumber(k)<<'\n';
    return 0;
}