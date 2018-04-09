#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
ifstream f("petrol.in");
ofstream g("petrol.out");
float E[101],D[101];
int e,n,d;
void citire()
{f>>n>>e>>d;
 for(int i=1;i<=n;i++)
 {float x,y;
  f>>x>>y;
  E[i]=e/x;
  D[i]=d/y;
 }
}
float maxs[101],maxj[101];
void creare(int n)
{maxs[1]=-1;
 maxj[n]=-1;
 for(int i=2;i<=n;i++)maxs[i]=max(D[i-1],maxs[i-1]);
 for(int i=n-1;i>=1;i--)maxj[i]=max(D[i+1],maxj[i+1]);
}
void calcul(int n)
{float maxim=0;
 if(n>1)
 {for(int i=1;i<=n;i++)
  if(maxim<E[i]+max(maxj[i],maxs[i]))maxim=E[i]+max(maxj[i],maxs[i]);
   g<<setprecision(6)<<maxim;
 }
 else g<<setprecision(6)<<max(E[1],D[1]);
}
int main()
{citire();
 creare(n);
 calcul(n);
    return 0;
}
