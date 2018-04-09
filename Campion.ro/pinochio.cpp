///http://campion.edu.ro/arhiva/index.php?page=problem&action=view&id=912
#include <fstream>
using namespace std;
ifstream f("pinochio.in");
ofstream g("pinochio.out");
int n,p,k;
void citire(int&n,int&p,int&k)
{f>>n>>p>>k;}
int s;
void zile(int&s)
{int i,z=0;
 s=n;
 for(i=1;i<=k;i++)
 {z++;
  switch(z)
   {case 1:{s=s+p;break;}
    case 2:{s=s+p;break;}
    case 3:{s=s+p;break;}
    case 4:{s=s+p;break;}
    case 5:{s=s+p;break;}
    case 6:{s--;break;}
    case 7:{s--;z=0;break;}
   }
 }
}
int main()
{citire(n,p,k);
 zile(s);
 g<<s;
    return 0;
}
