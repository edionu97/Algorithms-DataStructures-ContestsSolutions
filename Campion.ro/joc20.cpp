#include <fstream>
#define lengh 1001
using namespace std;
ifstream f("joc20.in");
ofstream g("joc20.out");
int v[lengh],x[lengh],n;
void citire()
{f>>n;
 for(int i=1;i<=n;i++)f>>v[i];
 for(int i=1;i<=n;i++)f>>x[i];
}
void afisare(int a,int b)
{int p=max(a,b);
 if(p>a)g<<p<<" "<<2;
 else
  if(p>b)g<<p<<" "<<1;
 else g<<p<<" "<<0;
}
void winner(int x[lengh],int v[lengh])
{int andr=0,tud=0,p=1,m=n;
 for(int i=1;i<=n;i++)
  if(i%2!=0)
   if(x[i]==1)
   {andr+=v[p];
    p++;
   }
   else
   {andr+=v[m];
    m--;
   }
  else
   if(x[i]==1)
   {tud+=v[p];
    p++;
   }
   else
   {tud+=v[m];
    m--;
   }
afisare(andr,tud);
}
int main()
{citire();
 winner(x,v);
     return 0;
}
