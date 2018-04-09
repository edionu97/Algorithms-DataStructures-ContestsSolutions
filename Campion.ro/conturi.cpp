#include <fstream>
using namespace std;
ifstream f("conturi.in");
ofstream g("conturi.out");
short n,x;
bool masc(int a)
{a/=10000;
 if(a%10==1)return 1;
 return 0;
}
int suma(int a)
{int nr=0,p=1;
 while(a>100)
 {nr+=p*(a%10);
  p*=10;
  a/=10;
 }
 return nr;
}
void citire()
{f>>n>>x;
 int a,max=0,b;
 for(short i=1;i<=n;i++)
 {f>>a;
  if(masc(a)&&(a/100000)==x)
  {b=suma(a);
   if(b>max)max=b;
  }
 }
g<<max;
}
int main()
{citire();
 return 0;
}
