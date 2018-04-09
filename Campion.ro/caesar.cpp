#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
using namespace std;
ifstream f("cezar.in");
ofstream g("cezar.out");
char v[257];
int x[258];
void citire()
{f.get(v,256);
 for(int i=1;i<=10;i++)f>>x[i];
}
bool val[255];
double modul(double a)
{return abs(a);
}
void car(int i,int k,int n)
{int nr=0;
 for(int j=i+1;j<n;j++)
 {if(v[j]!=' ')nr++;
  if(nr==10)
  {int dif=v[j]-'A';
   if(v[j]-x[k]<65)v[j]=char(65+26-modul(dif-x[k]));
    else v[j]=char(v[j]-x[k]);
   nr=0;
   val[j]=1;
  }
 }
}
void decod(char v[256])
{int n=strlen(v),k=1;
 for(int i=0;i<n;i++)
  if(v[i]!=' '&&!val[i])
  {int dif=v[i]-'A';
   if(v[i]-x[k]<65)v[i]=char(65+26-modul(dif-x[k]));
    else v[i]=char(v[i]-x[k]);
   car(i,k,n);
   val[i]=1;
   k++;
  }
  g<<v;
}
int main()
{citire();
 decod(v);
 return 0;
}
