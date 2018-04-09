#include <fstream>
#include <iostream>
using namespace std;
ifstream f("concurs3.in");
ofstream g("concurs3.out");
short n,m;
void citire()
{f>>m>>n;
 short a,s=(m/10)%10,o=(m/100)%10,ok=0;
 short luco=0,lucs=0;
 for(short i=1;i<=n;i++)
 {f>>a;
  if(a==m){g<<"DA";ok=1;}
  if((a/100)%10==o)luco++;
  if((a/10)%10==s&&(a/100)%10==o)lucs++;
 }
 if(ok==0)g<<"NU";
 g<<endl;
 g<<luco<<endl<<lucs;
}
int main()
{citire();
    return 0;
}
