#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
ifstream f("zar.in");
ofstream g("zar.out");
long n,k,f1,f2,f3;
void citire()
{f>>n>>k;
 f>>f1>>f2>>f3;
}
void sv1(long&k)
{long m=n-1,aux,rest;
 if(k-m<0)m=k;
 rest=m-4*(m/4);
 switch (rest)
 {case 3:{aux=f2;f2=f3;f3=7-aux;break;}
  case 2:{f2=7-f2;f3=7-f3;break;}
  case 1:{aux=f3;f3=f2;f2=7-aux;break;}
 }
k-=m;
}
void sv2(long&k)
{long m=n-1,aux,rest;
 if(k-m<0)m=k;
 rest=m-4*(m/4);
 switch(rest)
  {case 2:{f2=7-f2;f1=7-f1;break;}
   case 1:{aux=f1;f1=f2;f2=7-aux;break;}
   case 3:{aux=f2;f2=f1;f1=7-aux;break;}
  }
 k-=m;
}
void sv3(long&k)
{long m=n-1,aux,rest;
 if(k-m<0)m=k;
 rest=m-4*(m/4);
 switch(rest)
 {case 1:{aux=f2;f2=f3;f3=7-aux;break;}
  case 2:{f2=7-f2;f3=7-f3;break;}
  case 3:{aux=f3;f3=f2;f2=7-aux;break;}
 }
 k-=m;
}
void sv4(long&k)
{long m=n-1,aux,rest;
 if(k-m<0)m=k;
 rest=m-4*(m/4);
 switch(rest)
 {case 1:{aux=f2;f2=f1;f1=7-aux;break;}
  case 2:{f2=7-f2;f1=7-f1;break;}
  case 3:{aux=f1;f1=f2;f2=7-aux;break;}
 }
 k-=m;
}
void rez()
{int nr=0;
 do
 {nr++;
  switch(nr)
   {case 1:{sv1(k);break;}
    case 2:{sv2(k);break;}
    case 3:{sv3(k);break;}
    case 4:{sv4(k);nr=0;break;}
   }
 }while(k);
 g<<f1<<' '<<f2<<' '<<f3;
}
int main()
{citire();
 rez();
    return 0;
}
