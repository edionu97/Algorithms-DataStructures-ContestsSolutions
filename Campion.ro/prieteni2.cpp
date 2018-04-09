#include <fstream>
#include <algorithm>
using namespace std;
ifstream f("prieteni2.in");
ofstream g("prieteni2.out");
short v[1001],n;
void citire()
{f>>n;
 for(int i=1;i<=n;i++)f>>v[i];
}
bool cresc(short a,short b)
{return a<b;}
void prieteni(short v[1001])
{sort(v+1,v+n+1,cresc);
 long long timp=0;
 for(int i=2;i<=n;i++)
    if(i!=n)timp+=v[i]+v[1];
     else timp+=v[n];
 g<<timp;
}
int main()
{citire();
 prieteni(v);
    return 0;
}
