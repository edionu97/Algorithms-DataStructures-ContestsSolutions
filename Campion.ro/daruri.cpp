#include <fstream>
using namespace std;
ifstream f("daruri.in");
ofstream g("daruri.out");
short t,l;
void citire()
{f>>t>>l;}
int cmmdc(int a,int b)
{if(b)return cmmdc(b,a%b);
 return a;
}
void distribuire(int l,int t)
{if(t>l)
 {int a=cmmdc(t,l);
  if(a>=2)
  {g<<a<<endl;
   g<<t/a<<" "<<l/a;
  }
  else g<<0<<endl<<0<<endl<<0;
 }
 else
  {int a=cmmdc(l,t);
  if(a>=2)
  {g<<a<<endl;
   g<<t/a<<" "<<l/a;
  }
  else g<<0<<endl<<0<<" "<<0;
 }
}
int main()
{citire();
 distribuire(l,t);
    return 0;
}
