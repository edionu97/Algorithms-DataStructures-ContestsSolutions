#include <fstream>
using namespace std;
ifstream f("codcorect.in");
ofstream g("codcorect.out");
long long v[21],n;
void citire()
{f>>n;
 for(int i=1;i<=n;i++)f>>v[i];
}
short cif[10];
short imp_c(long long x)
{short nr=0;
 while(x)
 {cif[++nr]=x%10;
  x/=10;
 }
 return nr;
}
void trans(long long v[21])
{for(int i=1;i<=n;i++)
  {int p=imp_c(v[i]);
   if(p%2!=0)
    if(cif[1]>cif[p])
     {g<<cif[1];
      for(int j=p-1;j>=2;j--)g<<cif[j];
      g<<cif[p];
     }
  else g<<v[i];
  else g<<v[i];
   g<<' ';
  }
}
int main()
{citire();
 trans(v);
    return 0;
}
