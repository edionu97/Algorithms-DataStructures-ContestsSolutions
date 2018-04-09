#include <fstream>
#include <cstring>
#include <iostream>
#define lengh 200
using namespace std;
ifstream f("criptmat.in");
ofstream g("criptmat.out");
char a[lengh][lengh],v[202];
int n,m,comp;
void citire()
{f>>n;
 f.get();
 f.get(v,201);
}
void prelucr(int n,int&m,int&comp)
{m=strlen(v);
 int aux=m;
 while(m%n!=0)m++;
 comp=m-aux;
}
void s_d(int i,int&p)
{int j;
 for(j=1;j<=n;j++)a[i][j]=v[p++];
}
void d_s(int i,int&p)
{int j;
 for(j=n;j>=1;j--)a[i][j]=v[p++];
}
void complet(char a[lengh][lengh])
{int p=0;
 for(int i=1;i<=m;i++)
  if(i%2!=0)s_d(i,p);
  else d_s(i,p);
}
void afis(int n,int comp)
{for(int j=1;j<=n;j++)
  for(int i=1;i<=m/n;i++)g<<a[i][j];
 int d=120;
 while(comp!=0)
 {if(d<=122)g<<char(d);
  else d=97;
  d+=2;
  comp--;
 }
}
int main()
{citire();
 prelucr(n,m,comp);
 complet(a);
 afis(n,comp);
    return 0;
}
