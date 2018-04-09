#include <fstream>
using namespace std;
ifstream f("barca.in");
ofstream g("barca.out");
int n,i;
void citire()
{f>>n;
 g<<n*4<<'\n';
 for(int i=1;i<=n;i++)
 {g<<"IG"<<'\n';
  g<<"I"<<'\n';
  g<<i<<'\n';
  g<<"G"<<'\n';
 }
}
int main()
{citire();
 return 0;
}

