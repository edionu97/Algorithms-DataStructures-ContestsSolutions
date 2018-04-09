#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
ifstream f("mere.in");
ofstream g("mere.out");
struct mar
{int x,y,z,r;
}a[201];
short n;
void citire()
{f>>n;
 for(int i=1;i<=n;i++)
 {f>>a[i].x>>a[i].y>>a[i].z>>a[i].r;
  if(a[i].z<0)a[i].z+=a[i].r;
  else a[i].z-=a[i].r;
 }
}
double ssqrt(double xx)
{return sqrt(xx);
}
double modul(double xx)
{return abs(xx);
}
bool uz[201];
void sim(int i)
{int c[201];
 c[1]=1;
 int inc=1,sf=1;
 uz[1]=1;
 while(inc<=sf)
 {for(int i=1;i<=n;i++)
   if(a[c[inc]].z>a[i].z&&!uz[i])
    {int absc,ord;
     absc=a[c[inc]].x-a[i].x;
     ord=a[c[inc]].y-a[i].y;
      if(floor(ssqrt(modul(absc*absc-ord*ord)))<=a[c[inc]].r+a[i].r)
      {c[++sf]=i;
       uz[i]=1;
      }
    }
    inc++;
 }
 g<<sf;
}
int main()
{citire();
 sim(1);
 return 0;
}
