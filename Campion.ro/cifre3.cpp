#include <fstream>
using namespace std;
ifstream f("cifre3.in");
ofstream g("cifre3.out");
int a,b;
void citire()
{f>>a>>b;}
int v[10],z[10],d[10];
void comune(int a,int b)
{int i,ok=0;
 while(a)
  {z[a%10]++;
   v[a%10]=1;
   a/=10;
  }
  while(b)
   {z[b%10]++;
     d[b%10]=1;
    b/=10;
   }
for(i=0;i<=9;i++)
  if(d[i]&&v[i]){g<<i<<" ";ok=1;}
//if(!ok)g<<"-1";
  g<<endl;
}
void nrmax(int z[10])
{int i;
for(i=9;i>=0;i--)
  if(z[i]!=0)
    while(z[i])
     {g<<i;
      z[i]--;
     }
}
int main()
{citire();
 comune(a,b);
 nrmax(z);
    return 0;
}
