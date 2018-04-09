#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iomanip>
using namespace std;
ifstream f("ecuatii.in");
ofstream g("ecuatii.out");
char v[260];
int n;
void calc(char v[],int&rez,int&rezx)
{int m=strlen(v);
 rez=rezx=0;
 for(int i=m-1;i>=0;i--)
 {char rezu[25]="";
  int dim=-1;
  if(v[i]=='x')
  {i--;
   while(v[i]>='0'&&v[i]<='9'&&i>=0)rezu[++dim]=v[i--];
   if(dim==-1)rezu[++dim]='1';
   if(i>=0)rezu[++dim]=v[i];
   reverse(rezu+0,rezu+dim+1);
  rezx+=atoi(rezu);
  }
  else
  {while(v[i]>='0'&&v[i]<='9'&&i>=0)rezu[++dim]=v[i--];
   if(v[i]!='x'&&i>=0)rezu[++dim]=v[i];
   reverse(rezu+0,rezu+dim+1);
   rez+=atoi(rezu);
  }
 }
}
void rezultat(float a,float b,float c,float d)
{a-=b;
 d-=c;
 if(a==0&&d==0)g<<"infinit";
 else
 if(a==0&&d!=0)g<<"imposibil";
 else
  {double p=d/a;
    g<<setprecision(8)<<p;
  }
g<<'\n';
}
void rez(char v[])
{char *p;
int rez1=0,rezx1=0,rez2=0,rezx2=0;
 p=strtok(v,"=");
 calc(p,rez1,rezx1);
 p=strtok(NULL,"=");
 calc(p,rez2,rezx2);
 rezultat(rezx1,rezx2,rez1,rez2);
}
void citire()
{f>>n;
 f.get();
 for(int i=1;i<=n;i++)
 {f.get(v,260);
  rez(v);
  f.get();
 }
}
int main()
{citire();

    return 0;
}
