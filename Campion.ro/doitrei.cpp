#include <iostream>
#include <fstream>
#define lengh 201
using namespace std;
ifstream f("doitrei.in");
ofstream g("doitrei.out");
short v[lengh],x[lengh],p[lengh],n;
void citire()
{f>>n;
 for(int i=1;i<=n-1;i++)v[i]=x[i]=3;
 v[n]=x[n]=2;
}
int fol[lengh],lung;
void inmultire(int n)
{lung=1;
int j;
 for(int i=1;i<=n;i++)
  {int t=0;
   for(j=1;j<=n;j++)
   {t+=v[i]*x[j]+p[i+j-1];
    if(!fol[i+j-1]){lung++;fol[i+j-1]=1;}
    p[i+j-1]=t%10;
    t/=10;
   }
   if(t)
   if(!fol[i+j-1]){p[i+j-1]=t;lung++;fol[i+j-1]=1;}
  }
}
int main()
{citire();
 inmultire(n);
 for(int i=lung-1;i>=1;i--)g<<p[i];
    return 0;
}
