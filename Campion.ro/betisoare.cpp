#include <iostream>
#include <fstream>
#include <cstring>
#define lengh 1000010
using namespace std;
ifstream f("betisoare.in");
ofstream g("betisoare.out");
char v[lengh];
short n;
void inm(long long &nr,long &j,char p,long elem)
{long long solp=nr,ii;
 for(ii=j+1;ii<elem;ii++)
    {long long nr1=0;
     while(v[ii]=='I'&&ii<=elem){ii++;nr1++;}
      solp*=nr1;
     if(v[ii]!=p)break;
    }
 nr=solp;
 j=ii;
}
void sec(char v[lengh])
{long long elem=strlen(v),nr1=0;
  for(long j=0;j<elem;j++)
  {long long nr=0;
   char p;
   while(v[j]=='I'&&j<elem){nr++;j++;}
   p=v[j];
   if(p=='+')nr1+=nr;
   else
   {inm(nr,j,p,elem);
    nr1+=nr;
   }
 }
 g<<nr1<<'\n';
}
void citire()
{f>>n;
 f.get();
 for(short i=1;i<=n;i++)
 {f.get(v,lengh);
sec(v);
  f.get();
 }
}
int main()
{citire();
    return 0;
}
