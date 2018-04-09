///http://campion.edu.ro/arhiva/index.php?page=problem&action=view&id=1226
#include <fstream>
using namespace std;
ifstream f("cifru4.in");
ofstream g("cifru4.out");
long a;
int nr;
void citire(long&a,int&nr)
{f>>a;
 long aux=a;
 while(aux)
 {nr++;
  aux/=10;
 }
}
int x,i;
long v[100];
void nrdenrx(long a,int nr,int&i,long v[100])
{while(a)
 {if(a%nr==0)x++;
  else
  {i++;
   v[i]=a;
  }
  a/=10;
 }
}
int y;
void nrdenry(int i,long v[100],int&y)
{int b=1,p;
 do
 {for(p=b+1;p<=i;p++)if(v[b]>v[p]&&(v[b]-v[p])%nr==0)y++;
  b++;
 }while(b<=i);
}
void cifru4(int x,int y)
{g<<x+y;
}
int main()
{citire(a,nr);
 nrdenrx(a,nr,i,v);
 nrdenry(i,v,y);
 cifru4(x,y);
 return 0;
}
