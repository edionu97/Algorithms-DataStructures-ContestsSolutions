#include <fstream>
using namespace std;
ifstream f("genab.in");
ofstream g("genab.out");
short x[21],n;
void citire()
{f>>n;}
short validare(short k)
{if(x[k]==2&&x[k-1]==x[k]||x[k]==2&&x[k+1]==x[k])return 0;
 return 1;
}
void afisare(short k)
{for(short i=1;i<=k;i++)
  if(x[i]==1)g<<'a';
  else g<<'b';
 g<<endl;
}
void genab(short k)
{for(short i=1;i<=2;i++)
  {x[k]=i;
   if(validare(k))
     if(k==n)afisare(k);
   else genab(k+1);
  }
  x[k]=0;
}
int main()
{citire();
 genab(1);
    return 0;
}
