#include <iostream>
#include <fstream>
using namespace std;
ifstream f("piramide.in");
ofstream g("piramide.out");
long long  n,x,k;
bool alb[100002];
void citire()
{f>>n>>x>>k;
 for(int i=1;i<=k;i++)
 {int val;
  f>>val;
  alb[val]=1;
 }
}
long long gaus(long long val)
{return(val*(val+1))/2;
}
long long maxim(long long inc,long long sf)
{long nr=0;
 while(inc<=sf)
  {if(alb[inc])nr++;
   inc++;
  }
  return nr;
}
void rez(long long n)
{long nrp=0,val=1,inc=1,sf=3;
 long maxi=0,cart,poz,ok=0;
 do
 {long long cub=gaus(val+1);
  if(cub<=n)
    {n-=cub;
    ++nrp;
     }
  else break;
  if(x>=inc&&x<=sf){g<<nrp<<'\n';ok=1;}
  cart=maxim(inc,sf);
  if(maxi<cart)
  {maxi=cart;
   poz=nrp;
  }
  inc=sf+1;
  sf=inc+gaus(val+2)-1;
  val++;
 }while(n);
 if(!ok)g<<0<<'\n';
 g<<nrp<<'\n'<<n<<'\n';
 if(maxi)g<<poz;
 else g<<0;
}
int main()
{citire();
 rez(n);
    return 0;
}
