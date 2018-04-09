//in c[i][j] retin profitul maxim ce s-ar obtine in urma  unui concert ce se termina la ora j<=maxp;
#include <iostream>
#include <fstream>
using namespace std;
ifstream f("fbr.in");
ofstream g("fbr.out");
int n;
int maxp;
struct elem
{int d,s,p;
}a[1001];
void citire()
{f>>n;
 for(int i=1;i<=n;i++)
 {f>>a[i].d>>a[i].s>>a[i].p;
  maxp=max(maxp,a[i].s);
 }
}
int nro;
int poz(int li,int ls)
{bool ok=0;
 while(li<ls)
 {if(a[li].s>a[ls].s)
    {elem aux=a[li];
     a[li]=a[ls];
     a[ls]=aux;
     ok=!ok;
    }
  if(!ok)li++;
  else ls--;
 }
 return li;
}
 void quick(int li,int ls)
{if(li<ls)
  {int p=poz(li,ls);
   quick(li,p-1);
   quick(p+1,ls);
  }
}
long c[3][10001];
inline void p_d(int n)
{quick(1,n);
long  maxg=0;
int p,aux;
 if(n%2==0)p=2;
  else p=1;
 if(n==1)g<<maxp;
 else
 {for(int i=0;;i++)
   if(i+a[1].d<=a[1].s)c[1][i+a[1].d]=a[1].p;
    else break;
  int p1=1,p2=2;
  for(int i=2;i<=n;i++)
    {for(int j=1;j<=maxp&&j<=a[i].s;j++)
     if(a[i].d<=j)
      if(a[i].p+c[p1][j-a[i].d]>c[p1][j])c[p2][j]=a[i].p+c[p1][j-a[i].d];
      else c[p2][j]=c[p1][j];
     else c[p2][j]=c[p1][j];
      aux=p1;
      p1=p2;
      p2=aux;
    }
    for(int i=1;i<=maxp;i++)maxg=max(maxg,c[p][i]);
  g<<maxg;
 }
}
int main()
{citire();
 p_d(n);
 return 0;
}
