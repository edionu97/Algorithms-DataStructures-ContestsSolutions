#include <iostream>
#include <fstream>
#define max_l 255555
using namespace std;
ifstream f("lacusta.in");
ofstream g("lacusta.out");
long a[101][101],b[101][101],m,n;
void init(long m,long n)
{for(int i=1;i<m;i++)
  for(int j=1;j<=n;j++)b[i][j]=max_l;
}
void citire()
{f>>m>>n;
 for(int i=1;i<=m;i++)
  for(int j=1;j<=n;j++)f>>a[i][j];
 init(m,n);
}
void p_d(long n,long m)
{b[m][n]=a[m][n];
 for(int i=n-1;i>=1;i--)b[m][i]=a[m][n]+a[m][i];
 if(m==1)g<<b[1][1];
 else
 {for(int i=1;i<=n;i++)
   for(int j=i+1;j<=n;j++)
   {if(j!=n&&b[m-1][i]>a[m-1][i]+a[m-1][j]+b[m][j])b[m-1][i]=a[m-1][i]+a[m-1][j]+b[m][j];
     if(b[m-1][j]>a[m-1][i]+a[m-1][j]+b[m][i])b[m-1][j]=a[m-1][i]+a[m-1][j]+b[m][i];
   }
    if(m==2)g<<b[1][1];
   else
   {for(int lin=m-2;lin>1;lin--)
     for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
      {if(b[lin][i]>a[lin][i]+a[lin][j]+b[lin+1][j])b[lin][i]=a[lin][i]+a[lin][j]+b[lin+1][j];
       if(b[lin][j]>a[lin][i]+a[lin][j]+b[lin+1][i])b[lin][j]=a[lin][i]+a[lin][j]+b[lin+1][i];
      }
     for(int i=2;i<=n;i++)
      if(b[1][1]>a[1][1]+a[1][i]+b[2][i])b[1][1]=a[1][1]+a[1][i]+b[2][i];
      g<<b[1][1];
   }
 }
}
int main()
{citire();
 p_d(n,m);
    return 0;
}
