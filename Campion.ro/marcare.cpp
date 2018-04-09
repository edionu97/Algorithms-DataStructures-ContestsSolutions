#include <fstream>
using namespace std;
ifstream f("marcare.in");
ofstream g("marcare.out");
short v[257],n,k,s;
void citire()
{f>>n>>s>>k;}
void marcare(short s,short k,short n)
{v[s]=1;
 g<<s<<' ';
 int i=s+k;
 if(i>n)i=i-n;
 while(i<=n)
 {v[i]++;
  if(v[i]==1)g<<i<<' ';
  else
  if(v[i]==2)break;
  if(i+k>n)i=(i+k)-n;
  else
  if(i+k==n)
  {g<<n<<' ';
   v[n]=1;
   i=k;
  }
  else i+=k;
 }
 int nr=0;
 g<<'\n';
 for(int i=1;i<=n;i++)
 if(v[i]==0)nr++;
 g<<nr;
}
int main()
{citire();
 marcare(s,k,n);
    return 0;
}
