#include <fstream>
#include <iostream>
using namespace std;
ifstream d("pepsi.in");
ofstream g("pepsi.out");
int n,m,k,y[101],p,h,b,f;
char v[1001];
void citire()
{d>>n>>m>>k;
 d.get();
 d.getline(v,1001);
 for(int i=1;i<=m;i++)d>>y[i];
}
int x[101],z[101];
void formare_x(int y[101],int z[101])
{int i;
 for(i=1;i<=m;i++)
 {x[i]=k-y[i];
  z[i]=k;
 }
}

void maxi(int x[101],int&p)
{int max=0;
 for(int i=1;i<=m;i++)
   if(x[i]>max)
   {max=x[i];
    p=i;
   }
}

void max_1(int x[101],int&p,int h)
{if(h==m)
  {int max=0;
   for(int i=1;i<=m;i++)
    if(x[i]>max)
     {max=x[i];
      p=i;
     }
  }
 else
  if(h+1<=m)
  {int max=0;
   for(int i=h+1;i<=m;i++)
   {if(x[i]>max)
     {max=x[i];
      p=i;
     }
    if(i==m)i=0;
    else
     if(i==h)break;
   }
  }
}

void max_z(int z[101],int&b,int&f,int h)
{if(h==m)
  {b=0;
   for(int i=1;i<=m;i++)
    if(x[i]!=0&&z[i]>b)
    {b=z[i];
     f=i;
    }
  }
 else
  if(h+1<=m)
  {b=0;
   for(int i=h+1;h<=m;i++)
    {if(x[i]!=0&&z[i]>b)
     {b=z[i];
     f=i;
     }
     if(i==m)i=0;
     else
      if(i==h)break;
    }
  }
}
void pepsi(int x[101],char v[1001])
{formare_x(y,z);
for(int i=0;i<n;i++)
  if(v[i]=='E')
  {maxi(x,p);
   g<<p<<" ";
   x[p]--;
   z[p]--;
   h=p;
   if(v[i+1]=='E')
   {i++;
    while(v[i]=='E'&&x[p]!=0)
    {g<<p<<" ";
     x[p]--;
     z[p]--;
     if(x[p]==0&&v[i+1]=='E')
     {maxi(x,p);
      h=p;
     }
     i++;
    }
    i--;
   }
  }
  else
   if(v[i]=='R')
   {if(i==0)h=1;
    max_1(x,p,h);
    max_z(z,b,f,h);
    if(z[p]==b)
    {g<<p<<" ";
     z[p]--;
     x[p]--;
     h=p;
    }
    else
    {g<<f<<" ";
     z[f]--;
     x[f]--;
     h=f;
    }
   }
}

int main()
{citire();
 pepsi(x,v);
 return 0;
}
