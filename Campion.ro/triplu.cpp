#include <fstream>
#include <iostream>
using namespace std;
ifstream f("triplu.in");
ofstream g("triplu.out");
int  m,n,l1,l2;
int v[5],x[5];
void citire()
{f>>m>>n;}
void cifrare(int v[5],int x[5],int m,int n)
{while(m)
 {v[++l1]=m%10;
  m/=10;
 }
 while(n)
 {x[++l2]=n%10;
  n/=10;
 }
}
int comparare(int v[5],int x[5])
{if(l1<l2)
 {int p=l2-l1;
  for(int i=l1;i>=1;i--)
  if(v[i]>x[i+p])return 1;
  else
   if(v[i]<x[i+p])return 2;
  return 2;
 }
 else
 if(l1>l2)
 {int p=l1-l2;
  for(int i=l2;i>=1;i--)
  if(x[i]>v[i+p])return 2;
  else
   if(v[i+p]>x[i])return 1;
  return 1;
 }
 else
 {for(int i=l1;i>=1;i--)
  if(v[i]>x[i])return 1;
   else
    if(v[i]<x[i])return 2;
  return 0;
 }
}
int putere(int x)
{int p=1;
 while(x)
 {p*=10;
  x--;
 }
 return p;
}
void triplu(int m,int n)
{switch(comparare(v,x))
 {case 0:{long long nr=(m*putere(l1)+n)*3;g<<nr;break;}
  case 1:{long long nr=(m*putere(l2)+n)*3;g<<nr;break;}
  case 2:{long long nr=(n*putere(l1)+m)*3;g<<nr;break;}
 }
}
int main()
{citire();
 cifrare(v,x,m,n);
 triplu(m,n);
    return 0;
}
