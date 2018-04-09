#include <fstream>
#include <iostream>
using namespace std;
ifstream f("cifra1.in");
ofstream g("cifra1.out");
long n,poz,ok;
void citire()
{f>>n>>poz;}
void cif(long n)
{if(n&&!ok)
  {short c=n%10;
    cif(n/10);
    if(!ok)
    if(c<poz)poz-=c;
    else
    {ok=1;
     g<<c;
    }
  }
}
int main()
{citire();
 cif(n);
    return 0;
}
