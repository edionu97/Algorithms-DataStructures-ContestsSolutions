///http://campion.edu.ro/arhiva/index.php?page=problem&action=view&id=990
#include <fstream>
#include <algorithm>
using namespace std;
ifstream f("balcon.in");
ofstream g("balcon.out");
int n,a[50][50],p,v[2500];
void citire(int&n,int a[50][50],int&p,int v[2500])
{int i,j;
 f>>n;
 for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
   {f>>a[i][j];
    p++;
    v[p]=a[i][j];
   }
}
int x,y;
bool cresc(int x,int y)
{return x<y;
}
void sortare(int p,int v[2500])
{sort(v+1,v+p+1,cresc);
}
void balcon(int a[50][50],int p,int v[2500])
{int c=1,b=n,m=1,i,j;
do
 {i=c;
  for(j=c;j<=b;j++)
  {a[i][j]=v[m];
   m++;
  }
  j=b;
  for(i=c+1;i<=b;i++)
  {a[i][j]=v[m];
   m++;
  }
  i=b;
  for(j=b-1;j>=c;j--)
  {a[i][j]=v[m];
   m++;
  }
  j=c;
  for(i=b-1;i>c;i--)
  {a[i][j]=v[m];
   m++;
  }
  c++;
  b--;
 }while(m<=n*n);
}
void afisare(int a[50][50])
{int i,j;
 for(i=1;i<=n;i++)
 {for(j=1;j<=n;j++)g<<a[i][j]<<" ";
  g<<endl;
 }
}
int main()
{citire(n,a,p,v);
 cresc(x,y);
 sortare(p,v);
 balcon(a,p,v);
 afisare(a);
 return 0;
}
