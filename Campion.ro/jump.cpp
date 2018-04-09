#include <iostream>
#include <fstream>
using namespace std;
ifstream f("jump.in");
ofstream g("jump.out");
short n;
long long v[1001];
void citire()
{f>>n;}
void rez(int n)
{v[n]=1;
 v[n-1]=1;
 v[n-2]=2;
 long long s=0;
 for(int i=n-3;i>=1;i--){v[i]=(v[i+1]+v[i+2]+v[i+3])%666013;}
 for(int i=1;i<=3;i++)s=(s+v[i]%666013);
 g<<s;
}
int main()
{citire();
 if(n==1)g<<1;
 else
    if(n==2)g<<2;
  else rez(n);
    return 0;
}
