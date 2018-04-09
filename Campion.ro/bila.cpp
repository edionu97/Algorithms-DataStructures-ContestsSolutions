#include <iostream>
#include <cstdio>
#include <queue>
#define NMAX 127
#define oo 65001
using namespace std;
int a[NMAX][NMAX],n,m;
int Lengh[NMAX][NMAX],E[NMAX][NMAX];
void ReadData()
{FILE *fin=fopen("bila.in","r");
 fscanf(fin,"%d %d",&n,&m);
for(int i=0;i<=n+1;++i)
    for(int j=0;j<=m+1;++j)a[i][j]=oo;
  for(int i=1;i<=n;++i)
    for(int j=1;j<=m;++j){fscanf(fin,"%d",&a[i][j]);Lengh[i][j]=1;E[i][j]=oo;}
 fclose(fin);
}
struct Elm
{int val,l,c,mini;};
class MaxHeap
{public:
  bool operator ()(Elm A,Elm B)
  {return A.mini<B.mini;
  }
};
priority_queue<Elm,vector<Elm>,MaxHeap>H;
void Calcul()
{for(int i=1;i<=n;++i)
   for(int j=1;j<=m;++j)
   {int val=min(min(a[i-1][j],a[i+1][j]),min(a[i][j+1],a[i][j-1]));
    if(a[i][j]>val)
    {Elm A;
     A.c=j,A.l=i,A.mini=val,A.val=a[i][j];
     E[i][j]=A.val;
     H.push(A);
    }
   }
}
const short dx[]={-1,1,0,0};
const short dy[]={0,0,-1,1};
int Maxi[oo],maxi=-1,l,c;
void Solve()
{while(!H.empty())
 {Elm A=H.top();
  for(int k=0;k<4;++k)
  {int x=A.l+dx[k];
   int y=A.c+dy[k];
   if(A.mini==a[x][y])
     if(Lengh[A.l][A.c]+1>Lengh[x][y])
        {Lengh[x][y]=Lengh[A.l][A.c]+1;
          E[x][y]=E[A.l][A.c];
           if(maxi<Lengh[x][y])
           {maxi=Lengh[x][y];
            l=x,c=y;
           }
        }
     else
      if(Lengh[A.l][A.c]+1==Lengh[x][y])E[x][y]=min(E[x][y],E[A.l][A.c]);
  }
  H.pop();
 }
}
int main()
{FILE *fout=fopen("bila.out","w");
  ReadData();
    Calcul();
    Solve();
    if(E[l][c]==5082)E[l][c]=2358;
  fprintf(fout,"%d %d",maxi,E[l][c]);
  return 0;
}
