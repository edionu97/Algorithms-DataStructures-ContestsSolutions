///http://campion.edu.ro/arhiva/index.php?page=problem&action=view&id=994
#include <fstream>
using namespace std;
ifstream f("prodmax.in");
ofstream g("prodmax.out");
long n,cif;
void citire(long &n,long &cif)
{long aux;
 f>>n;
 aux=n;
 while(aux)
 {cif++;
  aux/=10;
 }
}
void prodmax(long cif,long n)
{long max=-32000000,aux,ok,aux2,p=1,c,nr,a,b;
 do
 {ok=0;
  aux=n;
  aux2=1;
  p=1;
  nr=0;
  while(aux2<=cif-1)
  {c=aux%10;
   nr=nr+p*c;
   p=p*10;
   aux/=10;
   aux2++;
  }
  cif--;
  if(aux*nr>max)
  {max=aux*nr;
   a=aux;
   b=nr;
  }
  if(cif==1)ok=1;
 }while(!ok);
g<<max<<endl;
g<<a<<endl;
g<<b;
}
int main()
{citire(n,cif);
 prodmax(cif,n);
 return 0;
}
