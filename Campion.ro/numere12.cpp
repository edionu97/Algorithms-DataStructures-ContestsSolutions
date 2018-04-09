#include <fstream>
using namespace std;
ifstream f("numere12.in");
ofstream g("numere12.out");
int ls,ld;
void citire()
{f>>ls>>ld;}
int resp(int x,int i)
{while(x)
  {if(x%10!=0)
   if(i%(x%10)!=0)return 0;
   x/=10;
  }
 return 1;
}
void nr(int ls,int ld)
{int nr=0;
 for(int i=ls;i<=ld;i++)
  if(resp(i,i))nr++;
  g<<nr;
}
int main()
{citire();
 nr(ls,ld);
    return 0;
}
