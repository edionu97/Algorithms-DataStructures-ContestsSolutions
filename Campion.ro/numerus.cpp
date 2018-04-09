#include <fstream>
using namespace std;
ifstream f("numerus.in");
ofstream g("numerus.out");
long long k,n;
void citire()
{f>>k>>n;}
void nr_dek(long long n)
{if(k%2==0)
 {long long a=k*5;
  g<<a<<" ";
  for(long long i=a;i>=a-4;i--)g<<i<<" ";
 }
else
{long long a=k*5;
 for(long long i=a-4;i<=a;i++)g<<i<<" ";
 g<<a;
}
g<<endl;
}
void det_linie(long long n)
{long long i=n/5;
 if(i*5>=n)g<<i;
 else g<<++i;
 g<<endl;
 if(i%2==0)
  {long long a=i*5,nr=1;
    for(long long j=a;j>=a-4;j--)
     {if(j==n&&j==a){g<<'A'<<" "<<'B';break;}
      if(j==n)break;
      else nr++;
     }
   if(nr>1)g<<char('A'+nr);
  }
 else
 {long long a=i*5,nr=0,j;
  bool ok=1;
  for(j=a-4;j<=a;j++)
   {if(j==a&&j==n){g<<'E'<<" "<<'F';ok=0;}
    if(j==n)break;
    else nr++;
   }
  if(ok)g<<char('A'+nr);
 }
}
int main()
{citire();
 nr_dek(n);
 det_linie(n);
    return 0;
}
