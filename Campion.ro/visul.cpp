#include <fstream>
#include <cmath>
using namespace std;
ifstream f("visul.in");
ofstream g("visul.out");
int n;
void citire()
{f>>n;
}
int prim(int   x)
{int d;
 for(d=2;d<=sqrt(x);d++)
  if(x%d==0)return 0;
 if(x==1)return 0;
 else return 1;
}
int secventa(int  x)
{int nr=0,p=0,c=1;
 while(x)
 {p=p+(x%10)*c;
  c*=10;
  nr++;
  if(nr==2)
  {if(!prim(p))return 0;
   if(p<9)return 0;
   while(p>9)p/=10;
   nr=1;
   c=10;
  }
  x/=10;
 }
 return 1;
}
void parcurgere(int n)
{long   i;
 for(i=pow(10,n-1)*n;i<=3525548;i++)
  {if(secventa(i))
    {g<<i;
     break;
    }
  }
}
int main()
{citire();
parcurgere(n);
    return 0;
}
