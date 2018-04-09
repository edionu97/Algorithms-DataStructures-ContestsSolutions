#include <iostream>
#include <fstream>
#define lengh 10001
using namespace std;
ifstream f("cladiri2.in");
ofstream g("cladiri2.out");
long v[lengh],x[lengh];
short n;
short maxim;
short prel(long d)
{short maxi=0;
 while(d)
 {if(d%10>maxi)maxi=d%10;
  d/=10;
 }
 return maxi;
}
void citire()
{f>>n;
 for(short i=1;i<=n;i++)
 {f>>v[i];
  x[i]=prel(v[i]);
  if(x[i]>maxim)maxim=x[i];
 }
 short nr=0;
 g<<maxim<<' ';
 for(int i=1;i<=n;i++)if(x[i]==maxim)nr++;
 g<<nr<<'\n';
}
bool palindrom(long h)
{long aux=h,inv=0;
 while(aux)
 {inv=inv*10+aux%10;
  aux/=10;
 }
 return inv==h;
}
void palindromice(short n)
{short nr=0;
 for(short i=1;i<=n;i++)if(palindrom(v[i]))nr++;
 g<<nr<<'\n';
}
short dif(long a)
{short nr=0,ca[10],cb[10];
 int i=0;
 while(a)
 {ca[++i]=a%10;
  a/=10;
 }
 int j=1;
 while(j<i)
 {short e=min(ca[i],ca[j]);
  short d=max(ca[i--],ca[j++]);
  nr+=d-e;
 }
return nr;
}
void crest_c(short n)
{int nr=0;
 for(int i=1;i<=n;i++)if(!palindrom(v[i]))nr+=dif(v[i]);
 g<<nr;
}
int main()
{citire();
 palindromice(n);
 crest_c(n);
    return 0;
}
