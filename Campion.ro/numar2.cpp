#include <fstream>
#include <cmath>
#include <iostream>
using namespace std;
ifstream f("numar2.in");
ofstream g("numar2.out");
long long n;
const double a=0.333333333;
void citire()
{f>>n;}
int palindrom(long long x)
{int inv=0;
 while(x)
 {inv=inv*10+(x%10);
  x/=10;
 }
 return inv;
}
void nr(long long n)
{float b=pow(n,a);
 for(int i=b;i>=0;i--)
  if(palindrom(i*i*i)==i*i*i)
  {g<<i*i*i;
   break;
  }

}
int main()
{citire();
 nr(n);
    return 0;
}
