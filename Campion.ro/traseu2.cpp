#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream f("traseu2.in");
ofstream g("traseu2.out");
int a[101][101];
int n,li,lj,m;
char v[256];
void citire()
{f>>n>>li>>lj;
 for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)f>>a[i][j];
 f.get();
 f.get(v,256);
 m=strlen(v);
 cout<<strlen(v);
}
int ok(int i,int j)
{return i>0&&j>0&&i<=n&&j<=n&&a[i][j]==0;}
void rez(int m)
{for(int i=0;i<m;i++)
  switch(v[i])
   {case 'N':
        {int ii=li-1;
         if(ok(ii,lj))li=ii;
          break;
        }
     case 'S':
       {int ii=li+1;
        if(ok(ii,lj))li=ii;
        break;
       }
     case 'E':
      {int jj=lj+1;
       if(ok(li,jj))lj=jj;
       break;
      }
     case 'V':
       {int jj=lj-1;
        if(ok(li,jj))lj=jj;
        break;
       }
   }
 g<<li<<' '<<lj;
}
int main()
{citire();
 rez(m);
    return 0;
}
