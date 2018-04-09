#include <fstream>
#include <iostream>
using namespace std;
ifstream f("scara.in");
ofstream g("scara.out");
long long n;
void a_o(long long n)
{long long a=n/4;
 if(n>=(a*4+1)&&n<=(a*4+4))
 {g<<((a*4+4)-n)+n/4+1<<" ";
  g<<a;
 }
 else
 {g<<(((a-1)*4+4)-n)+n/4<<" ";
  g<<a;
 }
}
int main()
{f>>n;
 a_o(n);
    return 0;
}
