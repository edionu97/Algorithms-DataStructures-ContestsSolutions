#include <iostream>
#include <fstream>
using namespace std;
ifstream f("adunscad.in");
ofstream g("adunscad.out");
int v[22],n,s_d[22],m;
void citire()
{f>>n>>m;
 for(int i=1;i<=m;i++)f>>v[i];
}
int cond(int k,int s)
{if(k==m+1&&s==n)return 0;
 return 1;
}
int ok;
void afis()
 {for(int i=1;i<=m;i++)
  if(s_d[i]==1&&i!=1)g<<'+'<<v[i];
      else
     if(s_d[i]==1&&i==1)g<<v[i];
     else
     if(s_d[i]==2)g<<'-'<<v[i];

 }
void back(int k,int s)
{if(!cond(k,s))
  {ok=1;
   afis();}
 for(int i=1;i<=2&&!ok;i++)
 {s_d[k]=i;
  if(k<=m)
  if(s_d[k]==1)back(k+1,s+v[k]);
  else
    if(s_d[k]==2) back(k+1,s-v[k]);
 }
}
int main()
{citire();
 back(1,0);
  if(!ok)g<<'0'<<'\n';
  return 0;
}
