#include <fstream>
#define maxn 30000
using namespace std;
ifstream f("cluburi.in");
ofstream g("cluburi.out");
short n;
void citire()
{f>>n;}
void cluburi(short n)
{short p=1;
 do
 {if(n%2!=0)
  {n/=2;
   g<<p<<" ";
   p*=2;
  }
  else n/=2,p*=2;
 }while(n>1);
 g<<p;
}
void nr_de_club(short n)
{short nr=1;
 do
 {if(n%2!=0)
  {n/=2;
   nr++;
  }
  else n/=2;
 }while(n>1);
 g<<nr<<endl;;
}
int main()
{citire();
 nr_de_club(n);
 cluburi(n);
 return 0;
}
