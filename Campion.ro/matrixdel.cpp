#include <fstream>
using namespace std;
ifstream f("matrixdel.in");
ofstream g("matrixdel.out");
short l,c,a[100][100];
short x[100],v[100];
void citire()
{f>>l>>c;
 for(short i=1;i<=l;i++)
  for(short j=1;j<=c;j++)f>>a[i][j];
 short q,p,j;
 f>>q;
 while(q)
 {f>>j;
  v[j]=1;
  q--;
 }
 f>>p;
 while(p)
 {f>>j;
  x[j]=1;
  p--;
 }
}
void afisare(short l,short c)
{for(short i=1;i<=l;i++)
  if(v[i]==0)
    {for(short j=1;j<=c;j++)
      if(x[j]==0)g<<a[i][j]<<" ";
     g<<endl;
    }
}
int main()
{citire();
 afisare(l,c);
 return 0;
}
