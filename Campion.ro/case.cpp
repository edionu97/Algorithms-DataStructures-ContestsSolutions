#include <fstream>
using namespace std;
ifstream f("case1.in");
ofstream g("case1.out");
long long  n;
void citire()
{f>>n;
 short a,nrc=0,nrf=0,nrb=0,nr1=0,nr2=0,nr3=0;
 for(short i=1;i<=n;i++)
 {f>>a;
  if(a%10<=9)nrc+=a%10;
  if((a/10)%10<=6)nrf+=(a/10)%10;
  if((a/100)%10<=6)nrb+=(a/100)%10;
  switch((a/1000)%10)
   {case 1:{nr1++;break;}
    case 2:{nr2++;break;}
    case 3:{nr3++;break;}
   }
 }
 g<<nr1<<endl<<nr2<<endl<<nr3<<endl<<nrb<<endl<<nrf<<endl<<nrc;
}
int main()
{citire();
 return 0;
}
