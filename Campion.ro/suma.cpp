#include <iostream>
#include <fstream>
using namespace std;
ifstream f("suma.in");
ofstream g("suma.out");
short mini[1001],maxi[1001],n;
void minim(int m)
{int val=9,p,rez,aux=m;
 mini[1]=1;
 m--;
 if(m)
 {while(m<val)val--;
  rez=m/val;
  m=m-rez*val;
  if(m!=0)p=m;
  while(rez)mini[aux--]=val,rez--;
  if(m)mini[aux]=p;
 }
}
void maxim(int m)
{int val=9,i=1;
 while(val>m)val--;
 int nrc=m/val;
 m=m-nrc*val;
 while(nrc)maxi[i++]=val,nrc--;
 if(m)maxi[i]=m;
}
int main()
{f>>n;
minim(n);
maxim(n);
for(int i=1;i<=n;i++)g<<mini[i];
g<<'\n';
for(int i=1;i<=n;i++)g<<maxi[i];
    return 0;
}
