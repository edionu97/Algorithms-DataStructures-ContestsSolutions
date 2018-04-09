#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream f("jucarii.in");
ofstream g("jucarii.out");
int n,m,q;
void citire()
{f>>n>>m>>q;}
int sol[12],nrs,ok=1;
std::vector<int>lung(17);
int p_d(int n)
{std::fill(lung.begin(),lung.end(),0);
 lung[n]=1;
 int maxi=0;
 for(int i=n-1;i>=1;i--)
 {lung[i]=1;
  for(int j=i+1;j<=n;j++)
    if(sol[i]<sol[j]&&lung[i]<=lung[j]){lung[i]=lung[j]+1;maxi=max(lung[i],maxi);}
 }
 return maxi>=m;
}
int cond(int k)
{for(int i=1;i<k;i++)
  if(sol[k]==sol[i])return 0;
  return 1;
}
void afis(int k)
{for(int i=1;i<=k;i++)g<<sol[i]<<' ';
g<<'\n';
}
int nr=0;
void back()
{sol[1]=0;
 int k=1;
 do
 {while(sol[k]<n)
  {sol[k]++;
   if(cond(k))
   {if(k==n)
       if(p_d(n))nrs++;
     if(nrs==q){afis(n);ok=0;break;}
     else sol[++k]=0;
   }
  }
  if(!ok)break;
  k--;
 }while(k);
}
int main()
{citire();
 back();
    return 0;
}
