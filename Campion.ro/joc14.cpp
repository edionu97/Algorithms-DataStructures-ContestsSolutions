#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#define lengh 60002
using namespace std;
ifstream f("joc14.in");
ofstream g("joc14.out");
int v[lengh],frec[10],n;
void citire()
{f>>n;
long nr=0;
 for(int i=1;i<=n;i++)
 {f>>v[i];
 if(frec[v[i]]==0)nr++;
  frec[v[i]]++;
 }
 g<<nr<<'\n';
}
double rad(double m)
{return sqrt(m);
}
bool dcresc(int a,int b)
 {return frec[a]>frec[b];
 }
void afis(int n)
{int val=rad(n);
 g<<val<<'\n';
 sort(v+1,v+n+1,dcresc);
 int elem=1,j=1;
 do
 {for(int i=1;i<=val;i++)g<<v[elem++];
 g<<'\n';
 j++;
 }while(j<=val);
}
int main()
{citire();
 afis(n);
    return 0;
}
