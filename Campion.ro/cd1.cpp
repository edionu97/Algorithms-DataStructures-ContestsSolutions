#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cd1.in");
ofstream g("cd1.out");
long long n,p[301];
long long S;
void citire()
{f>>n>>S;
 for(long long i=1;i<=n;i++)
 {long long yi,ci;
  f>>yi>>ci;
  p[i]=p[i]-yi;
  p[ci]=p[ci]+yi;
 }
 S=S/n;
 for(long long i=1;i<=n;i++)p[i]=S-p[i];
}
void calculare(long long n)
{long long nr=1;
 for(long long i=1;i<=n;i++){nr*=(p[i]-1);nr=nr%9901;}
 g<<nr;
}
int main()
{citire();
 calculare(n);
    return 0;
}
