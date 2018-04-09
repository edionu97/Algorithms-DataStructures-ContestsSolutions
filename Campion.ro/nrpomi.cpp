#include <fstream>
using namespace std;
ifstream f("nrpomi.in");
ofstream g("nrpomi.out");
int n,t,v[1001];
void citire(int v[1001])
{int i;
 f>>n>>t;
 for(i=1;i<=n;i++)f>>v[i];

}
void nrpomi(int n,int v[1001],int t)
{long long  rez;
 rez=1;
 v[n+1]=v[n-1];
 for(int i=2;i<=n;i+=2)
  if(v[i-1]==v[i+1])rez=(rez*(t-1))%1234;
  else rez=(rez*(t-2))%1234;
 g<<rez;
}
int main()
{citire(v);
nrpomi(n,v,t);
 return 0;
}
