#include <fstream>
#include <algorithm>
using namespace std;
ifstream f("vraji.in");
ofstream g("vraji.out");
short n,v[100];
bool cresc(short a,short b)
{return a<b;}
void citire_s()
{f>>n;
 short a,b;
 for(short i=1;i<=n;i++)
 {f>>a>>b;
  v[i]=a*b;
 }
 if(n>1)sort(v+1,v+n+1,cresc);
}
short cmmdc(short a,short b)
{short r;
 r=a%b;
 while(r)
 {a=b;
  b=r;
  r=a%b;
 }
 return b;
}
short x[99];
bool cresc_2(short a,short b)
{return a<b;}
void afis(short n,short v[100])
{if(n>1)for(short i=1;i<n;i++)x[i]=cmmdc(v[i],v[i+1]);
 if(n>1)sort(x+1,x+n,cresc_2);
 if(n>1)g<<v[n]<<endl<<x[1];
 else g<<v[1]<<endl<<v[1];
}
int main()
{citire_s();
 afis(n,v);
    return 0;
}
