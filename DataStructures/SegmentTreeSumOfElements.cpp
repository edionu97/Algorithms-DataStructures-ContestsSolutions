#include <iostream>
#include <cstdio>
#define NMAX 4000
using namespace std;
int V[NMAX],Tree[NMAX],n;
void ReadData()
{FILE *fin=fopen("val.in","r");
 while(fscanf(fin,"%d",&V[++n])>0);
 --n;
}
void Build(int x,int a,int b)
{if(a==b)Tree[x]=V[a];
 else
 {int m=(a+b)/2;
  Build(2*x,a,m);
  Build(2*x+1,m+1,b);
  Tree[x]+=(Tree[2*x]+Tree[2*x+1]);
 }
}
int S;
void Query(int nod,int st,int dr,int x,int y)
{if(x<=st&&dr<=y)S+=Tree[nod];
 else
 {int m=(st+dr)/2;
  if(x<=m)Query(2*nod,st,m,x,y);//exista intevalul [x,m] inclus in [x,y]
  if(y>m)Query(2*nod+1,m+1,dr,x,y);//exista intevlaul [m+1,y] inclus in [x,y]
 }
}
int m;
int main()
{ReadData();
 Build(1,1,n);
 int m;
 cin>>m;
 for(int i=1;i<=m;++i)
 {int a,b;
  cin>>a>>b;
   S=0;
  Query(1,1,n,a,b);
  cout<<"Suma din intervalul [a,b] este="<<S<<'\n';
 }

    return 0;
}
