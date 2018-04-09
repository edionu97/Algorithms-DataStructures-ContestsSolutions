#include <fstream>
using namespace std;
ifstream f("submdisj.in");
ofstream g("submdisj.out");
unsigned  a[101][101],n,p;
void citire_formare()
{f>>n;
 for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++)a[i][j]=++p;
}
void afisare(unsigned v)
{int j;
 for(j=n;j>j-v;j--)
 {g<<a[v][j]<<ends;
  v--;
 }
 g<<endl;
}
void afisare_1(unsigned a[101][101],unsigned n)
{unsigned b=0,ok,j,p=1;
 do
 {ok=0;
  for(j=1;j<=n;j++)
   if(j+b>n)
   {ok=1;
    break;
   }
   else g<<a[j+b][j]<<ends;
  if(ok)afisare(b);
  else g<<endl;
  b++;
 }while(b<n);
}
int main()
{citire_formare();
 afisare_1(a,n);

    return 0;
}
