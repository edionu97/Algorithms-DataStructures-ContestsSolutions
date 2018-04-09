#include <fstream>
using namespace std;
ifstream f("baschet.in");
ofstream g("baschet.out");
int v[31],n;
void citire()
{f>>n;
 for(int i=1;i<=n;i++)f>>v[i];
}
bool amf[31];
void secvente(int n)
{int nr,j=1,nrj=0;
 double nrp=0;
 for(int i=1;i<n;i++)
 {nr=1;
  while(v[i]==v[i+1]&&i+1<=n)
  {i++;
   nr++;
  }
  if(nr>=2&&amf[nr]==0)
  {nrj+=nr;
   nrp+=v[i]*nr;
   amf[nr]=1;
   break;
  }
 }
 if(nrj==nrp&&nrp==0)g<<1<<' '<<v[1];
 else g<<nrj<<' '<<nrp;
}
int main()
{citire();
 secvente(n);
    return 0;
}
