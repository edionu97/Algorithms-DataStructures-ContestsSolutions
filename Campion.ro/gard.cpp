#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
ifstream f("grad.in");
ofstream g("grad.out");
char a[256][256],v[255];
short x[30],n,i;
void citire_grad()
{f>>n;
 f.get();
  f.get(v,256);
 for(int i=97;i<=122;i++)x[char(i)]=i-97+1;
}
void numar_cuv()
{char *p;
 p=strtok(v," ");
 while(p)
 {strcpy(a[++i],p);
  p=strtok(NULL," ");
 }
 g<<i<<'\n';
}
void grad_c()
{int nr=0,m;
long long s;
std::vector<long long>b(256*122);
std::fill(b.begin(),b.end(),0);
 for(int j=1;j<=i;j++)
   {m=strlen(a[j]);
    s=0;
    for(int mm=0;mm<m;mm++)s=s+x[a[j][mm]];
    if(b[s]==0)nr++;
    b[s]=1;
   }
 g<<nr;
}
int main()
{citire_grad();
 numar_cuv();
 grad_c();
    return 0;
}
