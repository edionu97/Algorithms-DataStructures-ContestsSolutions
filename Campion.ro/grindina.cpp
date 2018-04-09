#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <cmath>
#define Punct pair<int,int>
#define y second
#define x first
#define NMAX 101
using namespace std;
int n;
FILE *fin=fopen("grindina.in","r");
vector<Punct>V[NMAX];
void ReadData()
{fscanf(fin,"%d",&n);
 for(int i=1;i<=n;++i)
 {int nrp;
  fscanf(fin,"%d",&nrp);
   for(int j=1;j<=nrp;++j)
   {int x,y;
    fscanf(fin,"%d %d",&x,&y);
    V[i].push_back(make_pair(x,y));
   }
 }

}
double modul(double a)
{return abs(a);
}
inline int Determinant(Punct A,Punct B,Punct C)
{
    return (B.x-A.x)*(C.y-A.y)-(C.x-A.x)*(B.y-A.y);
}
int Arie[NMAX];
inline void Calcul_Arie(int j)
{
    for(int i=1;i<V[j].size()-1;++i)
      Arie[j]+=modul(Determinant(V[j][0],V[j][i],V[j][i+1]));

}

int Lot[NMAX];

bool Is_In_Lot(Punct X,int i)
{int S=0;
  for(int j=0;j<V[i].size();++j)
  {Punct A=V[i][j],B;
    if(j+1==V[i].size())B=V[i][0];
     else B=V[i][j+1];
   int val=modul(Determinant(X,A,B));
    if(!val)return 0;
     S+=val;
  }
  return S==Arie[i];
}
int m,nr,maxi=0;
void Solve()
{fscanf(fin,"%d",&m);
  for(int i=1;i<=m;++i)
  {int a,b;
   fscanf(fin,"%d %d",&a,&b);
    Punct X=make_pair(a,b);
    for(int j=1;j<=n;++j)
      if(Is_In_Lot(X,j))
        {++Lot[j];
         if(maxi<Lot[j])
         {maxi=Lot[j];
          nr=1;
         }
         else
            if(maxi==Lot[j])++nr;
        }
  }
}
void Write()
{FILE *fout=fopen("grindina.out","w");
if(!nr)nr=n;
 fprintf(fout,"%d\n",nr);
 nr=0;
  for(int i=1;i<=n;++i)
    {if(!Lot[i])++nr;
        if(Lot[i]==maxi)fprintf(fout,"%d ",i);
    }
  fprintf(fout,"\n%d\n",nr);
  if(!nr)fprintf(fout,"%d",nr);
  else
  for(int i=1;i<=n;++i)
    if(!Lot[i])fprintf(fout,"%d ",i);
 fclose(fout);
}
int main()
{ReadData();
 for(int i=1;i<=n;++i)Calcul_Arie(i);
 Solve();
 Write();
    return 0;
}
