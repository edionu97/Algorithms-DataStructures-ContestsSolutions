#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream f("prieteni3.in");
ofstream g("prieteni3.out");
bool a[101][101];
short n,A,k;
void citire()
{f>>n>>A>>k;
 for(int i=1;i<=n;i++)
  {short elem,y;
   f>>elem;
   for(int j=1;j<=elem;j++)
   {f>>y;
    a[i][y]=a[y][i]=1;
   }
  }
}
int uz[101],c[101];
int inc=1,sf=1;
void bfs(int A)
{uz[A]=1;
 c[1]=A;
 while(inc<=sf)
 {for(int i=1;i<=n;i++)
   if(a[i][c[inc]]&&!uz[i])
   {c[++sf]=i;
    uz[i]=1;
   }
  break;
 }
}
bool cresc(int a,int b)
{return a<b;
}
bool sc[101];
void pri(int n)
{bfs(A);
 inc=2;
  int nr=0;
 while(inc<=sf)
 {for(int i=1;i<=n;i++)
   if(a[c[inc]][i]&&!uz[i])
   {c[++sf]=i;
    uz[i]=uz[c[inc]]+1;
   }
   inc++;
 }
 sort(c+1,c+sf+1,cresc);
 for(int i=1;i<=sf;i++)
    if(uz[c[i]]==k)
    {sc[c[i]]=1;
     nr++;
    }
    if(k==0)
    {g<<1<<'\n';
     g<<A<<'\n';
    }
     else
      {g<<nr<<'\n';
     for(int i=1;i<=sf;i++)
      if(sc[c[i]])g<<c[i]<<' ';
      }
}
int main()
{citire();

 pri(n);
    return 0;
}
