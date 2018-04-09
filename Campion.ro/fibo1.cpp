#include <iostream>
#include <fstream>
#include <ctime>
#define lengh 50004
using namespace std;
ifstream f("fibo1.in");
ofstream g("fibo1.out");
short n;
int v[lengh/2];
void citire()
{f>>n;
 v[1]=v[2]=1;
 for(int i=3;i<=n;i++)v[i]=(v[i-1]+v[i-2])%46337;

}
void afis(short  n)
{g<<n%2<<'\n';
 if(n%2==0)
 {int a=n/2+1,b=n/2-1;
  g<<b<<' '<<a<<'\n';
  g<<v[b]<<'\n'<<v[a]<<'\n'<<v[n];
 }
 else
 {int a=n/2+1,b=n/2;
  g<<b<<' '<<a<<'\n';
  g<<v[b]<<'\n'<<v[a]<<'\n'<<v[n];
 }
}
int main()
{citire();
afis(n);
    return 0;
}
