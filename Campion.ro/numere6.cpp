#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
ifstream f("numere6.in");
ofstream g("numere6.out");
unsigned a,b,n,m;
int v[100],x[100];
void rep1(unsigned a)
{if(a)
 {rep1(a/2);
  v[++n]=a%2;
 }
}
void rep2(unsigned b)
{if(b)
 {rep2(b/2);
  x[++m]=b%2;
 }
}
void citire()
{f>>a>>b;
 rep1(a);
 rep2(b);
}
double putere(double j,double k)
{return pow(j,k);
}
void sv(unsigned n,unsigned m)
{int i=1,j=m;
 double c,d;
 bool ok=0;
 if(v[i]==x[j])
 {ok=1;
  while(i<=n&&j>=1)
  if(v[i]!=x[j])break;
  else i++,j--;
  if(i>n)c=0;
  if(j<1)d=0;
 }
 else g<<a+b;
 if(c!=0)
 {double j=n-i;
  c=0;
   for(int p=i;p<=n;p++)c+=v[p]*putere(2,j),j--;
 }
 if(d!=0)
 {double i=j-1;
  d=0;
  for(int p=1;p<=j;p++)d+=x[p]*putere(2,i),i--;
 }
 if(ok)g<<d+c;
}
int main()
{citire();
sv(n,m);
    return 0;
}
