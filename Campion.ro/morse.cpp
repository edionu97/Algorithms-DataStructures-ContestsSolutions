#include <fstream>
using namespace std;
ifstream f("morse.in");
ofstream g("morse.out");
int a,b;
void citire()
{f>>a>>b;}
int maxim(int b)
{int p,n=0,nr,aux;
 for(p=b;p>=a;p--)
 if(p%2!=0)
 {nr=0;
  aux=p;
  while(p!=0)
  {if(p%2!=0)nr++;
   p/=2;
  }
  p=aux;
  if(n<nr)n=nr;
 }
 return n;
}
int maxim2(int a)
{int p,h=maxim(b),nr;
 for(p=a;p<=b;p++)
  if(p%2!=0)
 {nr=0;
  while(p)
  {if(p%2!=0)nr++;
   p/=2;
  }
  if(h<nr)h=nr;
 return h;
}
}
int v[100];
void afis(int v[100],int i)
{int j;
 for(j=i;j>=1;j--)
  if(v[j]==1)g<<"-";
  else g<<".";
  g<<" ";
}
void reprezentanta(int x,int &i)
{while(x)
 {v[++i]=x%2;
  x/=2;
 }
}
int nrmax(int x,int i)
{int j,nr=0;
 for(j=1;j<=i;j++)if(v[j]==1)nr++;
 if(nr==maxim2(a))return 1;
 else return 0;
}
void prelucrare(int a,int b)
{int j,i;
 for(j=a;j<=b;j++)
 {i=0;
  reprezentanta(j,i);
  if(nrmax(j,i))afis(v,i);
 }
}
int main()
{citire();
 prelucrare(a,b);
    return 0;
}
