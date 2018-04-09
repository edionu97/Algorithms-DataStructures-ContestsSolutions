#include <iostream>
#include <fstream>
using namespace std;
ifstream f("numar1.in");
ofstream g("numar1.out");
int v[51],n;
void citire()
{f>>n;
 for(int i=1;i<=n;i++)f>>v[i];
}
int z[51];
void gr(int&i,int&j)
{long s=v[i];
 while(v[i]<=v[i+1]&&i+1<=n)
 {s+=v[i+1];
  i++;
 }
z[++j]=s;
}
long ad(int p)
{long s=0;
 while(p)
 {s+=p%10;
  p/=10;
 }
 return s;
}
int fol[10];
void contr(int j)
{for(int i=1;i<=j;i++)
  {while(z[i]>9)z[i]=ad(z[i]);
   fol[z[i]]=1;
  }
}
void grup(int n)
{int i=1,j=0;
 for(int i=1;i<=n;i++)
  if(v[i]<=v[i+1]&&i+1<=n)gr(i,j);
  else z[++j]=v[i];
 contr(j);
}
void afis(int n)
{bool ok=0;
for(int i=9;i>=0;i--)
  if(!fol[i]){g<<i;ok=1;}
  if(!ok)g<<-1;
}
int main()
{citire();
 grup(n);
 afis(n);
    return 0;
}
