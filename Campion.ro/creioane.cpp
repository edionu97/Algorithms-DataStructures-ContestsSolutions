#include <iostream>
#include <fstream>
using namespace std;
ifstream f("creioane.in");
ofstream g("creioane.out");
struct nivel
{int p,q,val;
}v[9001];
int n,e[9001],nrv,niv[9001];
bool fol[9001];
void citire()
{f>>n;
 for(int i=1;i<=n;i++)
    {f>>v[i].p>>v[i].q;
     if(!v[i].p&&v[i].p==v[i].q){e[++nrv]=i;fol[i]=1;}
     v[i].val=i;
    }
}
void init(int nrv)
{for(int i=1;i<=nrv;i++)
 niv[v[e[i]].val]=1;
}
void niv_max(int nrv)
{bool ok;
 nrv=0;
 do
 {ok=0;
  for(int i=1;i<=n;i++)
    if(!fol[i])
     if(niv[v[i].p]&&niv[v[i].q]&&niv[v[i].p]==niv[v[i].q])
     {fol[i]=1;
      niv[i]=niv[v[i].p]+1;
      nrv=max(nrv,niv[i]);
      ok=1;
     }
 }while(ok);
 g<<nrv;
}
int main()
{citire();
 init(nrv);
 niv_max(nrv);
    return 0;
}
