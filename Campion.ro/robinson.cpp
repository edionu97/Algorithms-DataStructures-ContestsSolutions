#include <fstream>
#include <iostream>
#define lengh 101
using namespace std;
ifstream f("robinson.in");
ofstream g("robinson.out");
short m,n,l,c,a[lengh][lengh];
bool vectordrum[lengh][lengh];
void citire()
{f>>m>>n>>l>>c;}
void pl_pc(short a[lengh][lengh],short m)
{int nr=n-1;
 for(int i=1;i<=m;i++)a[1][i]=++nr;
 nr=n;
 for(int i=2;i<=m;i++)a[i][1]=++nr;
}
bool verfi(short x)
{if(x<1000)return 1;
 return 0;
}
short trunchere(short x)
{int nr=0,p=1;
 while(x>9)
 {nr=nr+p*(x%10);
  p*=10;
  x/=10;
 }
 return nr;
}
void form(short a[lengh][lengh],short m)
{for(int i=2;i<=m;i++)
  for(int j=2;j<=m;j++)
   {a[i][j]=a[i][j-1]+a[i-1][j];
    if(!verfi(a[i][j]))a[i][j]=trunchere(a[i][j]);
   }
 g<<a[m][m]<<endl;
}
void directie(int&ii,int&jj,int d)
{switch(d)
 {case 0:
  {ii--;
   break;
  }
  case 1:
   {jj++;
    break;
   }
   case 2:
    {ii++;
     break;
    }
  case 3:
   {jj--;
    break;
   }
 }
}
void gen_drum(short a[lengh][lengh],short m,int ii,int jj)
{int ok=0,d;
 do
 {ok=0;
  d=a[ii][jj]%4;
   if(!vectordrum[ii][jj]&&ii<=m&&jj<=m&&ii>=1&&jj>=1)
   {g<<ii<<" "<<jj<<endl;
    vectordrum[ii][jj]=1;
    directie(ii,jj,d);
   }
  else break;
 }while(!ok);
}
int main()
{citire();
 pl_pc(a,m);
 form(a,m);
 gen_drum(a,m,l,c);
    return 0;
}
