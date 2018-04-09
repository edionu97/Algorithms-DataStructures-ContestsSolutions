#include <fstream>
#include <cstring>
#include <cmath>
using namespace std;
ifstream f("cladiri2.in");
ofstream g("cladiri2.out");
char v[1000][10];
unsigned n;
void citire()
{unsigned i;
 f>>n;
 for(i=1;i<=n+1;i++)f.getline(v[i],9);
}
char  maxim(char v[1000][10])
{unsigned i,j;
 char x[10]="";
 unsigned char aux;
 unsigned char a,m;
 for(i=2;i<=n+1;i++)
 {strcpy(x,v[i]);
  a=x[0];
  for(j=1;j<strlen(x);j++)
  {aux=x[j];
   if(aux>a)a=aux;
  }
  if(i==2)m=a;
  else
    if(m<a)m=a;
 }
 return m;
}
void apel_1(char v[1000][10])
{g<<maxim(v)<<" ";
 unsigned char a=maxim(v);
 char x[10]="";
 unsigned i,nr=0;
 for(i=2;i<=n+1;i++)
 {strcpy(x,v[i]);
  if(strchr(x,a))nr++;
 }
 g<<nr;
}
void comparare(char v[1000][10])
{unsigned i,nr=0;
 for(i=2;i<=n+1;i++)
 {char x[10]="",y[10]="";
  strcpy(x,v[i]);
  strcpy(y,x);
  string strrev(x);
  if(strcmp(x,y)==0)nr++;
 }
 g<<endl;
 g<<nr<<endl;
}
unsigned x[10];
void nr_de_cub(char v[1000][10])
{unsigned i,j;
 unsigned char a,b;
 unsigned s=0,d=0,ok,p,f;
 char z[10]="",c[10]="";
 for(i=2;i<=n+1;i++)
 {strcpy(z,v[i]);
  strcpy(c,z);
 strrev(z);
  s=ok=p=0;
  for(j=0;j<strlen(c);j++)
  {a=z[j];
   b=c[j];
  f=abs(a-b);
   if(x[f]==0)
    {s+=f;
     ok=1;
     x[f]++;
    }
   else x[f]++;
  }
  if(ok==1)
    if(x[f]==strlen(c))
    {unsigned h=strlen(c)/2;
    while(h!=1){s+=f;h--;}
    }
 for(p=1;p<10;p++)x[p]=0;
 d+=s;
 }
 g<<d;
}

int main()
{citire();
 apel_1(v);
 comparare(v);
 nr_de_cub(v);
    return 0;
}
