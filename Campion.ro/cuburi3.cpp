#include <fstream>
#define lengh 1001
using namespace std;
ifstream f("cuburi3.in");
ofstream g("cuburi3.out");
short mini1,mini2,x[lengh],v[lengh],p[lengh],h[lengh],n;
void citire()
{f>>n;
 for(short i=1;i<=n;i++)
 {f>>v[i]>>x[i];
  if(p[v[i]]==0)
  {mini1++;
   p[v[i]]=1;
  }
 }
 for(short i=1;i<=n;i++)
 {if(h[x[i]]==0)
  {mini2++;
   h[x[i]]=1;
  }
 }
}
void solve(short mini1,short mini2)
{if(mini1<mini2)g<<"D"<<" "<<mini1;
 else
 if(mini1==mini2)g<<"DC"<<" "<<mini1;
 else g<<"C"<<" "<<mini2;
}
int main()
{citire();
 solve(mini1,mini2);
    return 0;
}
