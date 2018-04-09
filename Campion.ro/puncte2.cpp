#include <iostream>
#include <fstream>
using namespace std;
ifstream f("puncte2.in");
ofstream g("puncte2.out");
int fol[38],n;
void rez(int n)
{fol[2]=1;
 fol[4]=2;
 for(int i=6;i<=n;i+=2)
 {int nr1=0,nr2=i-2;
  while(nr2>=0)
  {fol[i]+=max(1,fol[nr1])*max(1,fol[nr2]);
   nr1+=2;
   nr2-=2;
  }
 }
 g<<fol[n]<<'\n';
}
int main()
{f>>n;
 rez(2*n);
    return 0;
}
