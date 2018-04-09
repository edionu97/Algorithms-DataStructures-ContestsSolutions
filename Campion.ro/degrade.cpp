#include <iostream>
#include <fstream>
#include <cstring>
#define lengh 100001
using namespace std;
ifstream f("degrade.in");
ofstream g("degrade.out");
char v[lengh],x[11];
int n;
void citire()
{f.get(x,11);
 f.get();
 f.get(v,lengh);
 n=strlen(v);
}
int elem[lengh];
void cres(char x[11])
{for(int i=0;i<10;i++)elem[x[i]]=i;}
void sec(int&i,int&nr)
{while(elem[v[i]]<=elem[v[i+1]]&&i+1<=n)
  {i++;
   nr++;
  }
}
int v_po[lengh];
int sub_max(char v[lengh])
{int maxi=0,i;
 cres(x);
 for(i=0;i<n-1;i++)
  {int nr=1,aux=i;
   if(elem[v[i]]<=elem[v[i+1]])sec(i,nr);
   if(nr>=maxi)
   {maxi=nr;
    v_po[aux]=v_po[i]=maxi;
   }
  }
 return maxi;
}
void afis(char v[lengh])
{int a=sub_max(v),nr=0;
 g<<a<<' ';
 for(int i=0;i<n;i++)
  if(v_po[i]==a)nr++;
 g<<nr/2;
}
int main()
{citire();
 afis(v);
 return 0;
}
