#include <fstream>
using namespace std;
ifstream f("alo.in");
ofstream g("alo.out");
short n,e;
short adun_scad(short a,short b)
{while(a>9)a/=10;
 if(a==1)return (-b*2);
 else
 if(a==2)return b;
 return 0;
}
void citire()
{f>>e>>n;
 short a,b;
 for(short i=1;i<=n;i++)
 {f>>a>>b;
  if(a%10!=9)e+=adun_scad(a,b);
 }
 g<<e;
}
int main()
{citire();
 return 0;
}
