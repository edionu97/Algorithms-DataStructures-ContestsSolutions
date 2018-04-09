#include <iostream>
#include <fstream>
#define lengh 5001
using namespace std;
ifstream f("flori2.in");
ofstream g("flori2.out");
unsigned long long v[lengh],n,sum[lengh],st[lengh];
void citire()
{f>>n;
int aux=0;
for(int i=n-2;i>=1;i--)
 {v[i]=(aux+sum[i+2]+1)%9001;
  sum[i]=(v[i]+sum[i+1])%9001;
  aux++;
 }
 g<<(sum[1]+n)%9001;
}
int main()
{citire();
    return 0;
}

