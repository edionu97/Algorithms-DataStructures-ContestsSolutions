#include <iostream>
#include <fstream>
using namespace std;
typedef unsigned long long mare;
ofstream g("unupatru.out");
ifstream f("unupatru.in");
mare nr,n,val;
void calcul(mare val)
{mare s=0,nr=0;
 if(val!=1&&val!=4)
 do
 {s=0;
  nr++;
  while(val)
  {s+=(val%10)*(val%10);
   val/=10;
  }
  val=s;
  if(val==0)break;
 }while(val!=1&&val!=4);
 g<<nr<<' ';
}
void citire()
{f>>n;
 for(int i=1;i<=n;i++)
 {f>>val;
  calcul(val);
 }
}
int main()
{citire();
    return 0;
}
