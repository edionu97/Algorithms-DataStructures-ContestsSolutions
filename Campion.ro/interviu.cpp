#include <iostream>
#include <fstream>
using namespace std;
ifstream f("interviu.in");
ofstream g("interviu.out");
short v[101],n;
void citire()
{f>>n;
 for(int i=1;i<=n;i++)f>>v[i];
}
void ang(short v[101])
{short maxi=0;
 bool ok=0;
 for(short i=1;i<=3;i++)
  if(v[i]>maxi)maxi=v[i];
 for(short i=4;i<=n;i++)
    if(v[i]>maxi)
     {g<<i;
      ok=1;
      break;
     }
 if(!ok)g<<n;
}
int main()
{citire();
 ang(v);
    return 0;
}
