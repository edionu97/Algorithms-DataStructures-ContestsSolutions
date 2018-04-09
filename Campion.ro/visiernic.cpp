#include <fstream>
using namespace std;
ifstream f("vistiernic.in");
ofstream g("vistiernic.out");
short n,a;
short divizibil_doi(int x)
{int d=0;
 while(x%2==0){x/=2;d++;}
 return d;
}
short divizibil_cinci(int x)
{int d=0;
 while(x%5==0){x/=5;d++;}
 return d;
}
void citire()
{int nr1=0,nr2=0;
 f>>n;
 for(int i=1;i<=n;i++)
 {f>>a;
  nr1+=divizibil_cinci(a);
  nr2+=divizibil_doi(a);
 }
 if(nr1>nr2)g<<nr2;
 else g<<nr1;
}
int main()
{citire();
    return 0;
}
