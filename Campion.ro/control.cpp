#include <fstream>
#include <algorithm>
using namespace std;
ifstream f("control.in");
ofstream g("control.out");
short n,v[101];
void citire()
{f>>n;
 for(short i=1;i<=n;i++)f>>v[i];
}
bool cresc(short a,short b)
{return a<b;}
short verif(int i)
{int l=i+3;
 if(v[i]%2==0)
 for(int j=i+1;j<l;j++)
    if(v[j]%2!=0)return 0;
 if(v[i]%2!=0)
  for(int j=i+1;j<l;j++)
    if(v[j]%2==0)return 0;
 return 1;
}
bool prim(int nr)
{for(int d=2;d<=nr/2;d++)
 if(nr%d==0)return 0;
 return 1;
}
void control(short v[101])
{sort(v+1,v+n+1,cresc);
 int num=0;
 for(int i=1;i<=n;i++)
 {num++;
  int j=i+1,nr=1;
  while(v[i]==v[j]){j++;nr++;}
  v[num]=nr;
  i=j-1;
 }
 while(num%3!=0)num--;
 int nr=0,nr1=0;
 for(int i=1;i<=num;i+=3)
  if(verif(i))nr++;
  else
    if(!verif(i))nr1++;
nr=nr*10+nr1;
g<<nr<<'\n';
g<<prim(nr);
}
int main()
{citire();
 control(v);
    return 0;
}
