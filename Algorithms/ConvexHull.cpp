#include <iostream>
#include <fstream>
#include <utility>
#include <algorithm>
#include <iomanip>
#define NMAX 120001
#define x first
#define y second
using namespace std;
ifstream f("infasuratoare.in");
typedef pair<double,double> Punct;
Punct V[NMAX];
inline double Determinant(Punct A,Punct B,Punct C)
{return (B.x-A.x)*(C.y-A.y)-(C.x-A.x)*(B.y-A.y);
}
inline bool Cmp(Punct A,Punct B)
{return Determinant(V[1],A,B)<0;
}
int n;
void Sortare()
{f>>n;
 int p=1;
 for(int i=1;i<=n;++i)
 {f>>V[i].x>>V[i].y;
  if(V[i]<V[p])p=i;
 }
 swap(V[1],V[p]);
 sort(V+2,V+n+1,Cmp);
}
Punct St[NMAX];
int top;
void ConvexHull()
{St[++top]=V[1];
 St[++top]=V[2];
 for(int i=3;i<=n;++i)
 {while(top>=2&&Determinant(St[top-1],St[top],V[i])>0)--top;
  St[++top]=V[i];
 }
}
void WriteSol()
{ofstream g("infasuratoare.out");
g<<top<<'\n';
 while(top)
 {g<<fixed<<setprecision(6)<<(double)St[top].x<<' '<<(double)St[top].y<<'\n';
  --top;
 }
}
int main()
{Sortare();
 ConvexHull();
 WriteSol();
    return 0;
}