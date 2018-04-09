#include <iostream>
#include <fstream>
using namespace std;
ifstream f("pachete.in");
ofstream g("pachete.out");
struct pach
{int in,t;
}a[100001];
int n;
void citire()
{f>>n;
 for(int i=1;i<=n;i++)f>>a[i].in>>a[i].t;
}
int  v[100001];
void p_d(int n)
{for(int i=1;i<=n;i++)
    v[i]=a[i].t+max(0,v[i-1]-a[i].in);

 g<<v[n];
}
int main()
{citire();
 p_d(n);
    return 0;
}
