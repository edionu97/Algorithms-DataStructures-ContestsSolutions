#include <iostream>
#include <fstream>
using namespace std;
ifstream f("vanatoare.in");
ofstream g("vanatoare.out");
long long ka,kb;
void citire()
{f>>ka>>kb;}
long long a=1,b=1,s,c;
void rez(long long ka,long long kb)
{long long nr=0;
 bool ok=1;
 if(ka-1<0){g<<0<<'\n'<<ka<<'\n'<<kb;ok=0;}
 else
  if(kb-1<0){g<<1<<'\n'<<ka-1<<'\n'<<kb;ok=0;}
 else
 {while(ka&&kb)
  {c=a+b;
  // cout<<c<<endl;
   a=b;
   if(a%2==0)
    if(ka-(a/2)>=0&&kb-(a/2)>=0)
     {nr++;
      ka-=a/2;
      kb-=a/2;
     }
    else break;
   else
    {long long aux=a;
    a--;
     if(ka-(a/2)>=0&&kb-(a/2)>=0)
     {ka-=a/2;
      kb-=a/2;
     }
      else break;
      if(ka-1<0)break;
      else
      {ka--;
       nr++;
      }
      a=aux;
    }
   b=c;
  }
 }
 if(ok){
g<<nr<<'\n';
g<<ka<<'\n';
g<<kb;}
}
int main()
{citire();
 rez(ka,kb);
    return 0;
}
