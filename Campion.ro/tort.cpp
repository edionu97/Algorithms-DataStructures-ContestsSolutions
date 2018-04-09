#include <fstream>
using namespace std;
ifstream f("tort.in");
ofstream g("tort.out");
int m,n;
void citire()
{f>>n>>m;}
int cmmdc(int d,int c)
{int r,aux,a=d,b=c;
 if(b>a)
 {aux=a;
  a=b;
  b=aux;
 }
 r=a%b;
 while(r)
 {a=b;
  b=r;
  r=a%b;
 }
 return b;
}
void tort(int m,int n)
{int b=cmmdc(m,n);
 g<<(m/b*n/b)<<" "<<b;

}
int main()
{citire();
 tort(m,n);
    return 0;
}
