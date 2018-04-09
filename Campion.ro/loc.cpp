#include <iostream>
#include <fstream>
using namespace std;
ifstream f("loc.in");
ofstream g("loc.out");
int v[1002 kl],n;
void citire()
{f>>n;
 for(int i=1;i<=n;i++)f>>v[i];
}
void rez(int n)
{int i=1,aux,elem,nr=-1,ok;
 do
 {ok=0;
  elem=v[i];
  while(v[i]&&i<=n)
     if(v[i]!=i)
      {aux=v[elem];
       v[i]=0;
       v[elem]=elem;
       i=elem=aux;
       ok=1;
      }
      else elem=v[++i];
  if(!v[i])v[i]=i,++nr;
 }while(ok);
 if(nr<0)g<<0;
 else g<<nr;
}
int main()
{citire();
 rez(n);
    return 0;
}
