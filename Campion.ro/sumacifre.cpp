#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
using namespace std;
ifstream f("sumacifre.in");
ofstream g("sumacifre.out");
long n;
short k;
void citire()
{f>>n>>k;}
int cif[10];
double modul(double nr)
{return abs(nr);
}
void transf(long&nr)
{int i=0;
 if(nr>9)
 {while(nr)
   {cif[++i]=nr%10;
    nr/=10;
   }
char v[10]="";
for(int j=i;j>1;j--)v[i-j]=floor(modul(cif[j]-cif[j-1]))+48;
nr=atol(v);
}
}
long long s;
void calc(int k)
{do
  {transf(n);
   s+=n;
   k--;
  }while(k);
  g<<s;
}
int main()
{citire();
 calc(k);
    return 0;
}
