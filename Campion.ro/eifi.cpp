#include <iostream>
#include <fstream>
using namespace std;
ifstream f("elfi.in");
ofstream g("elfi.out");
int m;
int uz[14440],maxi;
void calc(int x,int y)
{int s=x+y+1+x;
 for(int i=s-1;i<=14400;i+=s)
    {uz[i]++;
     maxi=max(uz[i],maxi);
    }
}
void citire()
{f>>m;
 for(int i=1;i<=m;i++)
 {int x,y;
  f>>x>>y;
  calc(x,y);
 }
}
int main()
{citire();
 g<<maxi;
    return 0;
}
