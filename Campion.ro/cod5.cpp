#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cod5.in");
ofstream g("cod5.out");
 long nr[99];
int main()
{long n,val;
 f>>n;

 for(int i=0;i<n;++i)
 {
  f>>val;
  ++nr[val];
 }
 for(int i=0;i<=99;++i)if(nr[i]%2)g<<i;

 return 0;
}
