#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define NMAX 10001
using namespace std;
vector<int>G[NMAX];
struct Elm
{int X,Y,C;
};
bool Comp(Elm A,Elm B)
{return A.C<B.C;
}
vector<Elm>H;
int n,m,p;
void ReadData()
{FILE *fin=fopen("flood.in","r");
 fscanf(fin,"%d %d",&n,&m);
 for(int i=1;i<=m;++i)
 {int x,y;
  fscanf(fin,"%d %d",&x,&y);
  G[x].push_back(y);
  G[y].push_back(x);
 }
 fscanf(fin,"%d",&p);
 for(int i=1;i<=p;++i)
 {Elm Val;
  fscanf(fin,"%d %d %d",&Val.X,&Val.Y,&Val.C);
  H.push_back(Val);
 }
 fclose(fin);
}
int Conexa[NMAX];
queue<int>Q;
void BFS(int x)
{Conexa[x]=x;
 Q.push(x);
 vector<int>::iterator it;
 while(!Q.empty())
 {x=Q.front();
  Q.pop();
  for(it=G[x].begin();it!=G[x].end();++it)
   if(!Conexa[*it])
   {Conexa[*it]=Conexa[x];
    Q.push(*it);
   }
 }
}
int Nrc,Cost;
vector<Elm>Sol;
void DetermCompConexe()
{for(int i=1;i<=n;++i)
  if(!Conexa[i])
  {++Nrc;
   BFS(i);
  }
}
void Unificare()
{Elm val;
 int Nrm=0;
 vector<Elm>::iterator it,sf=H.end();
 it=H.begin();
 while(it!=sf&&Nrc>Nrm)
 {val=*it;
  ++it;
  if(Conexa[val.X]!=Conexa[val.Y])
  {++Nrm;
   Sol.push_back(val);
   Cost+=val.C;
   int a=Conexa[val.X],b=Conexa[val.Y];
    for(int i=1;i<=n;++i)if(Conexa[i]==b)Conexa[i]=a;
  }
 }
}
void WriteSol()
{FILE *fout=fopen("flood.out","w");
 fprintf(fout,"%d\n%d\n",Nrc-1,Cost);
 n=Sol.size();
  for(int i=0;i<n;++i)
 {Elm val=Sol[i];
  fprintf(fout,"%d %d %d\n",val.X,val.Y,val.C);
 }
fclose(fout);
}
int main()
{ReadData();
 DetermCompConexe();
  sort(H.begin(),H.end(),Comp);
 Unificare();

WriteSol();
    return 0;
}
