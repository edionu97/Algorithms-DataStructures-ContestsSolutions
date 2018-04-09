#include <iostream>
#include <fstream>
using namespace std;
ifstream f("pion.in");
ofstream g("pion.out");
int a[202][202],n,m;
void citire()
{f>>m>>n;
 for(int i=1;i<=n;i++)f>>a[m+1][i];
 for(int i=1;i<=m;i++)f>>a[i][n+1];
}
void p_d(int n,int m)
{for(int i=m;i>=1;i--)
  for(int j=n;j>=1;j--)
     if((i+j)%2==0)a[i][j]=max(a[i+1][j],a[i][j+1]);
     else a[i][j]=min(a[i+1][j],a[i][j+1]);
 g<<a[1][1];
}
int main()
{citire();
 p_d(n,m);
 for(int i=1;i<=m+1;i++)
 {for(int j=1;j<=n+1;j++)cout<<a[i][j]<<' ';
  cout<<endl;
 }
    return 0;
}
