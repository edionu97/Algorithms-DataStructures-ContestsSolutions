#include <iostream>
#include <cstdio>
#define NMAX 500005
using namespace std;
FILE *fin=fopen("plopi.in","r");
int T[NMAX],V[NMAX],Val[NMAX/5];
int n,m;
void ReadData()
{fscanf(fin,"%d %d",&n,&m);
 for(int i=1;i<=n;++i)fscanf(fin,"%d",&Val[i]);
}
void BuildTree(int nod,int st,int dr)
{if(st==dr)
 {T[nod]=Val[st];
  V[nod]=st;
 }
 else
 {int m=(st+dr)/2;
  BuildTree(2*nod,st,m);
  BuildTree(2*nod+1,m+1,dr);
  if(T[2*nod]==T[2*nod+1])V[nod]=min(V[2*nod],V[2*nod+1]),T[nod]=T[2*nod];
  if(T[2*nod]>T[2*nod+1])
  {T[nod]=T[2*nod];
   V[nod]=V[2*nod];
  }
  if(T[2*nod]<T[2*nod+1]) T[nod]=T[2*nod+1],V[nod]=V[2*nod+1];
 }
}
int H;
void Update(int nod,int st,int dr,int a,int b)
{if(a<=st&&dr<=b)T[nod]=H;
 else
 {int m=(st+dr)/2;
  if(a<=m)Update(2*nod,st,m,a,b);
  if(b>m)Update(2*nod+1,m+1,dr,a,b);
   T[nod]=max(T[2*nod],T[2*nod+1]);
  if(T[2*nod]>T[2*nod+1])V[nod]=V[2*nod];
  else
   if(T[2*nod]<T[2*nod+1])V[nod]=V[2*nod+1];
   else V[nod]=min(V[2*nod],V[2*nod+1]);
 }
}
int val(int x)
{if(2*x<=NMAX&&T[2*x]>=H)return val(2*x);
 else
  if(2*x+1<=NMAX&&T[2*x+1]>=H)return val(2*x+1);
 return V[x];
}
int Tree;
void Query(int nod,int st,int dr,int a,int b)
{if(T[nod]<H)return;
 if(a<=st&&dr<=b)
  if(T[nod]==H)Tree=V[nod];
  else
   if(st!=dr)Tree=val(nod);
   else Tree=V[nod];
 else
 {int m=(st+dr)/2;
  if(a<=m&&Tree==-1)Query(2*nod,st,m,a,b);
  if(b>m&&Tree==-1)Query(2*nod+1,m+1,dr,a,b);
 }
}
FILE *fout=fopen("plopi.out","w");
int main()
{ReadData();
 BuildTree(1,1,n);
for(int i=1;i<=m;++i)
{int t,p;
  fscanf(fin,"%d %d %d",&t,&p,&H);
  Tree=-1;
  if(t==1)Update(1,1,n,p,p);
  else
  {Query(1,1,n,p,n);
   fprintf(fout,"%d\n",Tree);
  }
}
fclose(fin);
fclose(fout);
    return 0;
}
