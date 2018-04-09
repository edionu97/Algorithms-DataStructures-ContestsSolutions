#include <iostream>
#include <queue>
#include <cstdio>
#include <bitset>
#include <stack>
#define NMAX 101
using namespace std;
int A[NMAX][NMAX][NMAX];
int n,Mz,Mx,My,m,Ax,Ay,Az;
bitset<NMAX>Oc[NMAX][NMAX];
FILE *fout=fopen("traseu3.out","w");
void ReadData()
{FILE *fin=fopen("traseu3.in","r");
  fscanf(fin,"%d %d",&n,&m);
  fscanf(fin,"%d %d %d %d %d %d ",&Mz,&Mx,&My,&Az,&Ax,&Ay);
  Oc[Mz][Mx][My]=1;
  for(int i=1;i<=m;++i)
  {int x,y,z;
    fscanf(fin,"%d %d %d",&z,&x,&y);
    Oc[z][x][y]=1;
  }
  fclose(fin);
}
const short dz[]={-1,1};
const short dx[]={-1,1,0,0};
const short dy[]={0,0,-1,1};
struct Elm
{int niv,x,y;}val,X;
queue<Elm>Q;
inline bool cond(int a,int b,int c)
{return (a>=1&&a<=n&&b>=1&&b<=n&&c>=1&&c<=n);
}
inline bool Corect(int a,int b,int c,int d,int e,int f)
{return (!A[a][b][c]||A[a][b][c]>A[d][e][f]+1);
}
void Lee(int a,int b,int c)
{val.niv=a,val.x=b,val.y=c;
 Q.push(val);
 while(!Q.empty())
 {X=Q.front();
  Q.pop();
  for(int k=0;k<4;++k)
  {int xx=X.x+dx[k];
   int yy=X.y+dy[k];
    if(cond(X.niv,xx,yy)&&!Oc[X.niv][xx][yy])
        if(Corect(X.niv,xx,yy,X.niv,X.x,X.y))
        {A[X.niv][xx][yy]=A[X.niv][X.x][X.y]+1;
         val.niv=X.niv,val.x=xx,val.y=yy;
         Q.push(val);
         }
  }
  for(int k=0;k<2;++k)
  {int zz=X.niv+dz[k];
    if(cond(zz,X.x,X.y)&&!Oc[zz][X.x][X.y])
     if(Corect(zz,X.x,X.y,X.niv,X.x,X.y))
     {A[zz][X.x][X.y]=A[X.niv][X.x][X.y]+1;
      val.niv=zz,val.x=X.x,val.y=X.y;
      Q.push(val);
     }
  }
 }
}
const short Dx[]={-1,0,0,1};
const short Dy[]={0,-1,1,0};
stack<Elm>S;
void GetWay(int a,int b,int c)
{val.niv=a,val.x=b,val.y=c;
 S.push(val);
 int aux=A[Az][Ax][Ay];
 while(aux--)
 {bool ok=false;
   if(a-1>0&&!Oc[a-1][b][c]&&A[a-1][b][c]+1==A[a][b][c])
   {ok=true;
    val.niv=--a,val.x=b,val.y=c;
    S.push(val);
   }
   else
    for(int k=0;k<4;++k)
    {int x=b+Dx[k];
     int y=c+Dy[k];
     if(cond(a,x,y)&&A[a][b][c]==A[a][x][y]+1)
     {b=x,c=y;
      val.niv=a,val.x=b,val.y=c;
      S.push(val);
      ok=true;
      break;
     }
    }
  if(!ok)
  {val.niv=++a,val.x=b,val.y=c;
    S.push(val);
  }
 }
 while(!S.empty())
 {fprintf(fout,"%d %d %d\n",S.top().niv,S.top().x,S.top().y);
  S.pop();
 }
}
void WriteSol()
{fprintf(fout,"%d\n",A[Az][Ax][Ay]+1);
 GetWay(Az,Ax,Ay);
}
int main()
{ReadData();
 Lee(Mz,Mx,My);
 WriteSol();
    return 0;
}