#include <iostream>
#include <fstream>
#include <bitset>
#define lengh 3162278
using namespace std;
ifstream f("nrdiv.in");
ofstream g("nrdiv.out");
long long v[700000],x[51],maxi;
bool viz[lengh];
struct elem
{long p[25][25];
}po[51];
int n;
void citire()
{f>>n;
 for(int i=1;i<=n;i++)
 {f>>v[i];
  maxi=max(maxi,v[i]);
 }
}
int main()
{cout<<sizeof(viz)+sizeof(v)+sizeof(x)+sizeof(po);
    return 0;
}
