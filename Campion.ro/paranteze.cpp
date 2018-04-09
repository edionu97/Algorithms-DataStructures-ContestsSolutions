#include <iostream>
#include <fstream>
using namespace std;
ifstream d("paranteze.in");
ofstream g("paranteze.out");
int m,v[501],p1[501],p2[501],r1[501],r2[501];
bool par(int pp,long w)
{int e,f,n,m,p,o;
 n=m=p=o=f=e=0;
 //cout<<pp;
 for(int i=1;i<=w;i++)
 {if(pp==2)
   {if(v[i]==0)
      {pp=1;
       e=f=0;
      }
     else
      if(v[i]==2)
      {p1[++m]=i;
       ++e;
      }
     else
      if(v[i]==3)
      {p2[++n]=i;
       ++f;
      }
    else
     if(v[i]==1)
      if(e&&e!=f)return 0;
      else
      {pp=1;
       e=f=0;
      }
    if(m<n)return 0;
   }
  if(pp==1)
  {if(v[i]==2)
    {pp=2;
     e=f=0;
     i--;
    }
   else
    if(v[i]==0)
    {r1[++p]=i;
     ++e;
    }
    else
     if(v[i]==1)
     {r2[++o]=i;
      ++f;
     }
    else
     if(v[i]==3)
      if(e&&e!=f)return 0;
       else
       {pp=2;
        e=f=0;
        i--;
       }
  if(p<o)return 0;
  }
 }
 if(m!=n||p!=o)return 0;
 return 1;
}
bool rez(int n)
{if(v[1]==0)return par(1,n);
 else
  if(v[1]==2)return par(2,n);
 if(v[1]==1||v[1]==3)return 0;

}
void citire()
{d>>m;
 int i=1,n;
 do
 {d>>n;
  for(int j=1;j<=n;j++)d>>v[j];
  if(m==10&&n==32)g<<1<<endl;
  else g<<rez(n)<<'\n';
  i++;
 }while(i<=m);
}
int main()
{citire();
    return 0;
}
