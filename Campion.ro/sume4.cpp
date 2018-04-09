#include <fstream>
using namespace std;
ifstream f("sume4.in");
ofstream g("sume4.out");
unsigned n;
void suma(unsigned x,unsigned&s_a,unsigned&s_m)
{int i=1,p=1,nr=0,d;
 while(x>100)
 {if(i!=3)
  {nr=nr+p*(x%10);
   p*=10;
  }
  else d=x%10;
  x/=10;
  i++;
 }

 if(x<nr)
 {s_a+=d+x;
  s_m+=nr;
 }
 else if(x>nr)
 {s_m+=d+nr;
  s_a+=x;
 }
 if(x==nr)
 {s_a+=x;
  s_m+=x;
 }

}
void citire()
{f>>n;
 unsigned a,s_a=0,s_m=0;
 for(int i=1;i<=n;i++)
 {f>>a;
  suma(a,s_a,s_m);
 }
 g<<s_a<<" "<<s_m;
}
int main()
{citire();
 return 0;
}
