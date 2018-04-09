//se da un sir de n numere sa se raspunda la m intrebari de genul
//care este maximul din vector de pe poz [a,b]
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
void Build(int nod,int inf,int sup)
{if(inf==sup)Tree[nod]=V[inf];
 else
 {int m=(inf+sup)/2;
  Build(2*nod,inf,m);
  Build(2*nod+1,m+1,sup);
  Tree[nod]=max(Tree[2*nod],Tree[2*nod+1]);
 }
}
int m,maxi;
void Query(int nod,int inf,int sup,int x,int y)
{if(x>inf&&y>sup)return;
 if(x<=inf&&sup<=y)maxi=max(maxi,Tree[nod]);
 else
 {int m=(inf+sup)/2;
  if(x<=m)Query(2*nod,inf,m,x,y);
  if(y>m)Query(2*nod+1,m+1,sup,x,y);
 }
}
int main()
{ReadData();
 Build(1,1,n);
 cin>>m;
 for(int i=1;i<=m;++i)
 {int a,b;
  cin>>a>>b;
  maxi=-1;
  Query(1,1,n,a,b);
  if(maxi==-1)cout<<"Elemente inexistente";
  else
  cout<<"Maximul din intervalul [a,b] este="<<maxi;
 }
    return 0;
}
