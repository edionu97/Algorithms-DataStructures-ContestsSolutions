#include <iostream>
#include <fstream>
using namespace std;
ifstream f("bile3.in");
ofstream g("bile3.out");
int v[2001],x[2001],st[2001],p=-1,n;
char sol[6003]="";
void citire()
{f>>n;
 for(int i=1;i<=n;i++)f>>v[i];
 for(int i=1;i<=n;i++)f>>x[i];
}
bool pus[2001];
void rez(int n)
{int i=1,j=1,k=1,niv=1,ok=1;
 st[1]=v[1];
 pus[v[1]]=1;
 while(i<=n&&ok)
 {sol[++p]='I';
  while(st[niv]==x[k]&&niv&&k<=n)
    {niv--;
     k++;
     sol[++p]='O';
    }
  if(st[niv]!=x[k]&&pus[x[k]])ok=0;
  st[++niv]=v[++i];
  pus[v[i]]=1;
 }
if(ok)g<<sol<<endl;
else g<<"imposibil";
}
int main()
{citire();
 rez(n);
    return 0;
}
