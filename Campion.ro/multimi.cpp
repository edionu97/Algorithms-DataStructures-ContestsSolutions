#include <fstream>
using namespace std;
ifstream f("multimi.in");
ofstream g("multimi.out");
short n,u,p;
void citire(short&u,short&p)
{f>>n;
 short a,b;
 p=30000;
 for(short i=1;i<=n;i++)
 {f>>a>>b;
  if(a>u)u=a;
  if(b<p)p=b;
 }
}
void intersectie(short u,short p)
{if(p>u)
 for(short i=u;i<=p;i++)g<<i<<" ";
 else
  if(p==u)g<<p;
 else
  if(p<u)g<<"multimea vida";
}
int main()
{citire(u,p);
 intersectie(u,p);
    return 0;
}
