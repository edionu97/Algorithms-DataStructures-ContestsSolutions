#include <iostream>
#include <fstream>
using namespace std;
ifstream f("porumb1.in");
ofstream g("porumb1.out");
long long n,x;
void citire()
{f>>n>>x;}
void afis(long long n)
{if(n%2==0)g<<n/2<<'\n';
 else g<<n/2+1<<'\n';
 long long  val=n/2,nrt=0,poz,a=1,ok=0,nr;
 if(x%2!=0){poz=1;ok=1;}
 do
 {nrt++;
 if((x/a)%2&&!ok)
 {poz=nrt;
  ok=1;
 }
  if(n%2==0)
  {nr=n/2;
   if(n-nr)a=a*2;
   n-=nr;
  }
  else
  {nr=n/2+1;
   if(n-nr)a=a*2;
    n=n-nr;
  }
 }while(n);

 g<<nrt<<'\n'<<poz<<'\n'<<a;
}
int main()
{citire();
 afis(n);
    return 0;
}
