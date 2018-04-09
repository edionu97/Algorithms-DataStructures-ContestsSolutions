#include <fstream>
using namespace std;
ifstream f("prize.in");
ofstream g("prize.out");
long n;
void citire()
{f>>n;
 long a;
 int64_t sum=0;
 for(int i=1;i<n;i++)
 {f>>a;
  sum+=a-1;
 }
 f>>a;
 sum+=a;
 g<<sum;
}

int main()
{citire();
return 0;
}
