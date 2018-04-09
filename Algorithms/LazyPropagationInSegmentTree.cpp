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
void Build(int nod,int bg,int ed)
{if(bg==ed)Tree[nod]=V[bg];
 else
 {int m=(bg+ed)/2;
  Build(2*nod,bg,m);
  Build(2*nod+1,m+1,ed);
  Tree[nod]=min(Tree[2*nod],Tree[2*nod+1]);
 }
}
int U[NMAX],Val;
void Update(int nod,int bg,int ed,int x,int y)
{if(U[nod]!=0)
 {Tree[nod]+=U[nod];
  if(bg!=ed)U[2*nod]+=U[nod],U[2*nod+1]+=U[nod];
  U[nod]=0;
 }
 if(x<=bg&&ed<=y)
 {Tree[nod]+=Val;
  if(bg!=ed)U[2*nod]+=Val,U[2*nod+1]+=Val;
 }
 else
 {int m=(bg+ed)/2;
  if(x<=m)Update(2*nod,bg,m,x,y);
  if(y>m)Update(2*nod+1,m+1,ed,x,y);
  Tree[nod]=min(Tree[2*nod],Tree[2*nod+1]);
 }
}
int mini;
void Query(int nod,int st,int dr,int a,int b)
{if(U[nod]!=0)
 {Tree[nod]+=U[nod];
  if(st!=dr)U[2*nod]+=U[nod],U[2*nod+1]+=U[nod];
  U[nod]=0;
 }
 if(a<=st&&dr<=b)mini=min(Tree[nod],mini);
 else
 {int m=(st+dr)/2;
  if(a<=m)Query(2*nod,st,m,a,b);
  if(b>m)Query(2*nod+1,m+1,dr,a,b);
 }
}
int main()
{ReadData();
 Build(1,1,n);
 int m;
 FILE *fin1=fopen("inter.in","r");
 fscanf(fin1,"%d",&m);
 for(int i=1;i<=m;++i)
 {int a,b,c;
  mini=NMAX;
  fscanf(fin1,"%d %d %d",&a,&b,&c);
  if(a==0)
  {Query(1,1,n,b,c);
   cout<<mini<<'\n';
  }
  else
  {fscanf(fin1,"%d",&Val);
   Update(1,1,n,b,c);
  }
 }
return 0;
}
