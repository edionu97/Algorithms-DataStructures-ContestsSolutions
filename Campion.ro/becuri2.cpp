#include <iostream>
#include <fstream>
using namespace std;
ifstream f("becuri2.in");
ofstream g("becuri2.out");
bool andr[31],crist[31];
long long a,b;
short n;
void citire()
{f>>n>>a>>b;
 short i=0;
 while(a)
 {andr[++i]=(a%10)%2;
  a/=2;
 }
 i=0;
 while(b)
 {crist[++i]=(b%10)%2;
 b/=2;
 }
}
bool p[31];
void solve(short n,bool andr[31],bool crist[21])
{int stins=0,aprins=0,cons=0;
 for(int i=1;i<=n;i++)
  if(andr[i]==0&&crist[i]==1)aprins++;
  else
   if(andr[i]==1&&crist[i]==0)stins++;
  else
   if(andr[i]==crist[i]&&andr[i]==1)p[i]=1;
 g<<stins<<' '<<aprins<<' ';
 int maxi=0;
 for(int i=1;i<n;i++)
  {int nr=0;
   while(p[i]==1)
   {nr++;
    i++;
   }
  if(nr>maxi)maxi=nr;
  }
g<<maxi;
}
int main()
{citire();
 solve(n,andr,crist);
    return 0;
}
