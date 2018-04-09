#include <fstream>
using namespace std;
ifstream f("ingerasi.in");
ofstream g("ingerasi.out");
int n;
int64_t v[30];
void citire()
{f>>n;
 for(int i=1;i<=n;i++)f>>v[i];
}
int64_t cmmdc(int a,int b)
{if(b)return cmmdc(b,a%b);
 return a;
}
void rezolvare(int64_t v[30])
{int64_t i,min=1000000000;
 for(i=1;i<n;i++)
 {if(v[i]>v[i+1])
   {int a=cmmdc(v[i],v[i+1]);
    if(a<min)min=a;
   }
  else
  {int a=cmmdc(v[i+1],v[i]);
   if(a<min)min=a;
  }
 }
 g<<min;
}
int main()
{citire();
 rezolvare(v);
    return 0;
}
