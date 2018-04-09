#include <iostream>
#include <fstream>
using namespace std;
ifstream f("seif1.in");
ofstream g("seif1.out");
short n,k,a[101][101],delim;
void citire()
{f>>n>>k;
 for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++)f>>a[i][j];
  delim=n/2;
}
short v[201],x;

void cad_1(short a[101][101])
{int j=delim;
 for(int i=1;i<=delim;i++)v[++x]=a[i][j--];

}
void cad_2(short a[101][101])
{int i=delim+1;
 for(int j=1;j<=delim;j++)v[++x]=a[i++][j];
}

void cad_3(short a[101][101])
{short i=n;
 for(short j=delim+1;j<=n;j++)v[++x]=a[i--][j];
}

void cad_4(short a[101][101])
{short i=delim;
 for(short j=n;j>=delim+1;j--)v[++x]=a[i--][j];
}
int P[202];
void solve(short a[101][101])
{cad_1(a);cad_2(a);cad_3(a);cad_4(a);
 bool ok=1;
 short p=1,i=1;
 while(i<=x)
 {p++;
  i++;
  if(p>k) break;
  if(i>x)i=1;
 }
 if(i>x)i=1;
 P[i]=1;
 for(int j=i;j<=x;j++)
  {
  if(P[j]>1)break;
  else{P[j]++;g<<v[j]<<' ';}
   if(j==x)j=0;
  }
}
int main()
{citire();
 solve(a);
    return 0;
}
