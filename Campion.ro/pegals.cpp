#include <iostream>
#include <fstream>
using namespace std;
ifstream f("pegals.in");
ofstream g("pegals.out");
long long n;
void sv()
{f>>n;
g<<3<<endl;
 if(n%2==0)g<<1<<' '<<n/2-1<<' '<<n;
 else g<<1<<' '<<(n-1)/2<<' '<<n-1;
}
int main()
{sv();
    return 0;
}
