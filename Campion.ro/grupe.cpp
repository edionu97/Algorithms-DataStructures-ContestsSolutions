#include <iostream>
#include <fstream>
using namespace std;
ifstream f("grupe.in");
ofstream g("grupe.out");
unsigned long long v[91],n,sum[91];
void citire()
{f>>n;
 v[n]=v[n-1]=sum[n]=sum[n-1]=0;
 for(int i=n-2;i>=1;i--)
 {v[i]=v[i+1]+1;
  sum[i]+=sum[i+1]+v[i]+sum[i+2];
 }
}
void calcul(int n)
{unsigned long long s=n;
 for(int i=1;i<=n-2;i++)
  {s+=v[i];
   for(int j=i+2;j<=n-2;j++)s+=v[j]+sum[j+2];
  }
  g<<s;
}
int main()
{citire();
 calcul(n);
    return 0;
}
