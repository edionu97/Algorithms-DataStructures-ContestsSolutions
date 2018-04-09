#include <fstream>
#define lengh 100001
#include <iostream>
using namespace std;
ifstream f("subsecvmax.in");
ofstream g("subsecvmax.out");
long v[lengh],n;
void citire()
{f>>n;
 for(int i=1;i<=n;i++)f>>v[i];
}
void secv(int&i,int&nr)
{while(v[i]<=v[i+1]&&i<=n)
 {i++;
  nr++;
 }
}

void solve(long v[lengh])
{int nr,poz=0,maxi=-lengh,i;
 for(i=1;i<n;i++)
  {nr=1;
   int aux=i;
   if(v[i]<=v[i+1])secv(i,nr);
   if(nr>maxi){poz=aux;maxi=nr;}
  }
  if(i==1&&n==i)g<<1<<' '<<1;
 else
  g<<poz<<' '<<maxi;
}
int main()
{citire();
 solve(v);
    return 0;
}
