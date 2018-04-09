#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#define NMAX 203
#define oo 20000
using namespace std;
int n,m,x,k;
vector<int>G[NMAX],G2[NMAX];
void ReadGraph()
{FILE *fin=fopen("trasee.in","r");
 fscanf(fin,"%d %d %d %d",&n,&m,&x,&k);
 for(int i=1;i<=m;++i)
 {int X,Y;
  fscanf(fin,"%d %d",&X,&Y);
  G[X].push_back(Y);
  G[Y].push_back(X);
 }
 fclose(fin);
}
queue<int>Q;
bool Viz[NMAX];
int D[NMAX];
int C[NMAX][NMAX];
void MakeNewGraph(int x)
{Viz[x]=true;
 Q.push(x);
 vector<int>::iterator it;
 while(!Q.empty())
 {x=Q.front();
  Q.pop();
  for(it=G[x].begin();it!=G[x].end();++it)
   if(!Viz[*it])
   {D[*it]=D[x]+1;
    C[x][*it]=1;
    Viz[*it]=1;
    if(D[*it]==k-1)
    {C[*it][n+1]=oo;
     G2[*it].push_back(n+1);
     G2[n+1].push_back(*it);
    }
    G2[x].push_back(*it);
    G2[*it].push_back(x);
    Q.push(*it);
   }
   else
    if(D[*it]==D[x]+1)
    {G2[x].push_back(*it);
     G2[*it].push_back(x);
     C[x][*it]=1;
    }
 }
}
int Flow[NMAX][NMAX];
int Viz2[NMAX][NMAX];
bool Edmunds_Karp(int k,int vf)
{Viz2[k][vf]=vf;
 Q.push(vf);
 vector<int>::iterator it;
 while(!Q.empty()&&!Viz2[k][n+1])
 {vf=Q.front();
  Q.pop();
  for(it=G2[vf].begin();it!=G2[vf].end();++it)
   if(!Viz2[k][*it]&&C[vf][*it]-Flow[vf][*it]>0)
   {Viz2[k][*it]=vf;
    Q.push(*it);
   }
 }
 while(!Q.empty())Q.pop();
 return Viz2[k][n+1];
}
void Ford_Fulkenson()
{int flow=0;
 int k=-1;
 while(Edmunds_Karp(++k,x))
 {for(int i=n+1;i!=x;i=Viz2[k][i])
  {++Flow[Viz2[k][i]][i];
   Flow[i][Viz2[k][i]]=(-1)*Flow[Viz2[k][i]][i];
  }
  ++flow;
 }
 FILE *fout=fopen("trasee.out","w");
 fprintf(fout,"%d",flow);
 fclose(fout);
}
int main()
{ReadGraph();
 MakeNewGraph(x);
 Ford_Fulkenson();
    return 0;
}
