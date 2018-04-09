#include <fstream>
#define lengh 1000
using namespace std;
ifstream f("printesa.in");
ofstream g("printesa.out");
long long x[lengh],k,h,r[lengh];
void citire()
{f>>k>>h;
 for(int i=1;i<=h;i++)
 {f>>x[i];
  r[x[i]]=1;
 }
}
bool prim(long long i)
{for(long d=2;d<=i/2;d++)
  if(i%d==0)return 0;
 return 1;
}
void afisare(long long k)
{short nr=0;
 bool ok=1;
 long long i=2;
 while(ok)
 {if(r[i]==0&&prim(i))
   {nr++;
    r[i]=2;
   }
  if(nr==k)break;
  else i++;
 }
 for(long long j=i;j>=2;j--)if(r[j]==2)g<<j<<" ";
}
int main()
{citire();
 afisare(k);
    return 0;
}
