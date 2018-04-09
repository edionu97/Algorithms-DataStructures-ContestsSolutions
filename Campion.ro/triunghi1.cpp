#include <fstream>
#define lengh 10000
using namespace std;
ifstream f("triunghi1.in");
ofstream g("triunghi1.out");
short v[lengh],n,m;
void citire()
{f>>n>>m;}
void solve(short v[lengh])
{v[1]=1;
 short p=1;
 for(int i=2;i<=n;i++)
  {if(p<=9)
  {v[i]=v[i-1]+p;
   if(v[i]>10)v[i]=v[i]%10+1;
   if(v[i]==10)v[i]=1;
    p++;
  }
  if(p>9)p=1;
 }
 int j=1;
 for(int i=v[n];i<=9;i++)
 {if(j==m)
   {g<<i;
    break;
   }
  if(i==9)i=0;
  j++;
 }
}
int main()
{citire();
 solve(v);
 return 0;
}
