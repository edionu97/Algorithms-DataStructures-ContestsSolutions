#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;
ifstream f("chibrituri.in");
ofstream g("chibrituri.out");
short n,m,ne,i,mini_o=23,mini_min=59,maxi_o,maxi_min;
void citire()
{f>>n>>m;}
struct num
{int v,o;
}nr[10];
void atr()
{nr[0].v=4,nr[0].o=2;
 nr[1].v=2,nr[1].o=0,nr[2].v=2,nr[2].o=3,nr[3].v=2,nr[3].o=3,nr[9].o=3,nr[9].v=3;nr[4].v=3,nr[4].o=1,nr[5].v=2,nr[5].o=3,nr[6].v=nr[6].o=3,nr[7].v=2,nr[7].o=1,nr[8].v=4,nr[8].o=3;
}
bool ver1(int a,int b,int c,int d)
{if(nr[a].v+nr[b].v+nr[c].v+nr[d].v==n)return 1;
 return 0;
}
bool ver2(int a,int b,int c,int d)
{if(nr[a].o+nr[b].o+nr[c].o+nr[d].o==m)return 1;
 return 0;
}
void act(int a,int b)
{if(a<mini_o)
   {mini_o=a;
    mini_min=b;
   }
 if(a==mini_o&&b<mini_min)mini_min=b;
if(a>maxi_o)
 {maxi_o=a;
  maxi_min=b;
 }
if(a==maxi_o&&b>maxi_min)maxi_min=b;
}
void func1(int a)
{int b,c,d;
 for(b=0;b<=9;b++)
  for(c=0;c<=5;c++)
   for(d=0;d<=9;d++)
    if(ver1(a,b,c,d)&&ver2(a,b,c,d))
     {int hh=a*10+b,mm=c*10+d;
      if(!ne)
      {mini_o=hh;
       mini_min=mm;
       maxi_o=hh;
       maxi_min=mm;
      }
      else act(hh,mm);
      ne++;
     }
}
void func2(int a)
{int b,c,d;
 for(b=0;b<=3;b++)
  for(c=0;c<=5;c++)
   for(d=0;d<=9;d++)
    if(ver1(a,b,c,d)&&ver2(a,b,c,d))
    {int hh=a*10+b,mm=c*10+d;
      if(!ne)
      {mini_o=hh;
       mini_min=mm;
       maxi_o=hh;
       maxi_min=mm;
      }
      else act(hh,mm);
      ne++;
    }
}
void calc(short n,short m)
{int a,b,c,d;
for(a=0;a<=2;a++)
switch(a)
{case 0:{func1(a);break;}
 case 1:{func1(a);break;}
 case 2:{func2(a);break;}
}
}
void afisare()
{g<<ne<<'\n';
 if(mini_o<10)g<<0<<mini_o;
 else g<<mini_o;
 g<<":";
 if(mini_min<10)g<<0<<mini_min;
 else g<<mini_min;
 g<<'\n';
 if(maxi_o<10)g<<0<<maxi_o;
 else g<<maxi_o;
 g<<":";
 if(maxi_min<10)g<<0<<maxi_min;
 else g<<maxi_min;
}
int main()
{citire();
 atr();
 calc(n,m);
 afisare();
return 0;
}
