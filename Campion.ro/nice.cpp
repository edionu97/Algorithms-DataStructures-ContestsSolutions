#include <iostream>
#include <fstream>
using namespace std;
ifstream f("nice.in");
ofstream g("nice.out");
short n;
void citire()
{f>>n;}
void afis(short n)
{short nr=0;
 long long i=1,s=0;
 while(nr<n)
 {s=s+i;
  g<<i<<' ';
  i*=3;
  nr++;
 }
 g<<'\n';
 g<<s+1;
}
int main()
{citire();
 afis(n);
    return 0;
}
