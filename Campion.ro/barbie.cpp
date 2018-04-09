#include <iostream>
#include <fstream>
#define val 99999999
using namespace std;
ifstream f("barbie.in");
ofstream g("barbie.out");
struct elm
{int v,g;
}a[501];
int n,gp,pp;
void citire()
{f>>gp>>pp>>n;
 for(int i=1;i<=n;i++)f>>a[i].v>>a[i].g;
 pp-=gp;
}
long vec[10001];
void p_d(int n)
{for(int i=1;i*a[1].g<=pp;i++)vec[i*a[1].g]=i*a[1].v;
 if(n==1)g<<vec[pp];
 else
 {for(int i=2;i<=n;i++)
   for(int j=1;j<=pp;j++)
   {if(vec[j]==0)vec[j]=val;
     if(j%a[i].g==0)
     {if(vec[j-a[i].g]+a[i].v<vec[j])vec[j]=vec[j-a[i].g]+a[i].v;
      if(vec[j]>a[i].v*(j/a[i].g))vec[j]=a[i].v*(j/a[i].g);
     }
     else
      if(a[i].g<=j)
      if(vec[j-a[i].g]+a[i].v<vec[j])vec[j]=vec[j-a[i].g]+a[i].v;
  }
  g<<vec[pp];
}
}
int main()
{ citire();
p_d(n);
return 0;

}
