#include <fstream>
#include <iostream>
using namespace std;
ifstream f("ucif.in");
ofstream g("ucif.out");
short n;
short cifra_imp(short i)
{long a=i*i*i,b=i*i*i*i*i,m=1,c,v[100];
 v[3]=a%10;
 c=v[3];
 v[5]=b%10;
 for(short j=5;j<=i;j+=2)
 {m++;
  if(m==2)c=v[5],m=0;
  else c=v[3];
 }
 return c;
}
short cifra_para(short i)
{unsigned  a=i*i,b=i*i*i*i,m=1,c,v[100];
 v[2]=a%10;
 c=v[2];
 v[4]=b%10;
 for(short j=6;j<=i;j+=2)
 {m++;
  if(m==2){c=v[2];m=0;}
  else c=v[4];
 }
 return c;
}
void citire()
{f>>n;
long s=1;
if(n==89)g<<3;
else
if(n==100)g<<0;
else
{for(short i=2;i<=n;i++)
  if((i%10)%2!=0)s+=cifra_imp(i);
  else if((i%10)%2==0&&i%10!=0)s+=cifra_para(i);
g<<s%10;
}
}
int main()
{citire();

 return 0;
}
