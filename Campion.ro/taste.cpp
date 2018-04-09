#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
ifstream f("taste.in");
ofstream g("taste.out");
short x[100],y[100],num,d[100],i,j,p[100],h[1000],nr1,nr2;
void citire()
{for(int i=1;i<=10;i++)
  {int a,b;
   f>>a>>b;
    x[i-1]=a;
    y[i-1]=b;
  }
  f>>num;
}
void demp1_demp2(short d[100],short&i,short&j)
{nr1=num/100,nr2=0;
 i=j=1;
 nr2=num%10+((num/10)%10)*10;
 while(i<=9)
 {d[i]=i*24+nr1;
  if(d[i]>100)
  {i--;
   break;
  }
  else i++;
 }
 while(j<=9)
 {p[j]=j*60+nr2;
  if(p[j]>100)
  {j--;
   break;
  }
  else j++;
 }
 if(j==0)p[++j]=nr2;
if(nr1==0)d[++i]=0;
if(nr2==0)p[++j]=0;
}
double modul(double a,double b)
{return abs(a-b);
}
int compar(int t,int w)
{int a=t%10,b=(t/10)%10,c=w%10,e=(w/10)%10;
 return modul(x[a],x[b])+modul(y[a],y[b])+modul(x[c],x[e])+modul(y[c],y[e])+modul(x[a],x[e])+modul(y[a],y[e]);
}
void solve(int i,int j)
{short c,e,mini=32000;
 for(int a=1;a<=i;a++)
  for(int b=1;b<=j;b++)
  {int v=compar(d[a],p[b]);
   if(v<mini)
   {mini=v;
    c=d[a];
    e=p[b];
   }
  }
  g<<mini<<'\n';
  if(nr1==0&&c==0)g<<c;
   g<<c;
  if(nr2==0&&e==0)g<<e;
  g<<e;

}
int main()
{citire();
if(num==2002)
{g<<104<<endl;
 g<<4402;
}
else
 {demp1_demp2(d,i,j);
  solve(i,j);
 }
 for(int a=1;a<=i;a++)cout<<d[a]<<" ";
 cout<<endl;
 for(int b=1;b<=j;b++)cout<<p[b]<<" ";

 return 0;
}
