#include <iostream>
#include <fstream>
using namespace std;
ifstream f("triunghi3.in");
ofstream g("triunghi3.out");
long long n;
void rez(long long n)
{long long a,b;
 a=2,b=1;
 while(n>1)
  if(n%2==0)
  {n/=2;
   a=(a*a)%2011;
  }
  else
  {b=(b*a)%2011;
   a=(a*a)%2011;
   n/=2;
  }
  g<<(a*b)%2011-2;
}
int main()
{f>>n;
 rez(n);
    return 0;
}
