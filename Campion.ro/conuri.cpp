#include <iostream>
#include <fstream>
#define MAX_T 100001
using namespace std;
ifstream f("conuri.in");
ofstream g("conuri.out");
struct con
{long f[4];
}a[MAX_T];
int n;
void citire()
{f>>n;
 for(int i=1;i<=n;i++)f>>a[i].f[1]>>a[i].f[2];
}
long long L[MAX_T],F[MAX_T],maxm[MAX_T];
long long  maxi;
void p_d(int n)
{for(int i=1;i<=n;i++)
 {L[i]=1;
  F[i]=-1;
  maxm[i]=1;
  long f1=a[i].f[1],f2=a[i].f[2],ff1,ff2;
  for(long j=1;j<i;j++)
  {ff1=a[j].f[1];
   ff2=a[j].f[2];

   if(L[i]==1)
    {if(f1==ff1||f1==ff2)
    {L[i]=2;
     F[i]=2;
    }
    else
     if(f2==ff1||f2==ff2)
     {L[i]=2;
      F[i]=1;
     }
    }

    if(F[j]!=-1)
      if(f1==a[j].f[F[j]]&&L[i]<L[j]+1){L[i]=L[j]+1;F[i]=2;}
       else
       if(f2==a[j].f[F[j]]&&L[i]<L[j]+1){L[i]=L[j]+1;F[i]=1;}
  }
  maxi=max(maxi,L[i]);
  maxm[i]=maxi;
 }
g<<maxi;
}
int main()
{citire();
 p_d(n);
    return 0;
}
