#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <cstring>
#define NMAX 101
#define oo 1
using namespace std;
vector<int>G[NMAX];
int n,m;
int C[NMAX][NMAX],F[NMAX][NMAX];
void ReadData()
{FILE *fin=fopen("val.in","r");
 fscanf(fin,"%d %d",&n,&m);
 for(int i=1;i<=m;++i)
 {int x,y;
  fscanf(fin,"%d %d",&x,&y);
  G[x].push_back(y);
  C[x][y]=1;
 }
 fclose(fin);
}
void BuildGraph()
{for(int i=1;i<=n;++i)
  if(!G[i].size()){G[i].push_back(n+1);C[i][n+1]=oo;}
  else {G[0].push_back(i);C[0][i]=oo;}
}
queue<int>Q;
int T[NMAX];
int Edmunds_Krap()
{memset(T,-1,sizeof(T));
 vector<int>::iterator it;
 Q.push(0);
 T[0]=0;
 while(!Q.empty()&&T[n+1]<0)
 {int x=Q.front();
  Q.pop();
  for(it=G[x].begin();it!=G[x].end();++it)
     if(C[x][*it]-F[x][*it]>0&&T[*it]<0)
     {T[*it]=x;
      Q.push(*it);
     }
 }
 while(!Q.empty())Q.pop();
 return T[n+1];
}
void Flux()
{int Card=0;
 while(Edmunds_Krap()>0)
  {++Card;
   for(int i=n+1;i!=0;i=T[i])
   {F[T[i]][i]+=1;
    F[i][T[i]]=(-1)*F[T[i]][i];
   }
  }
  cout<<Card<<'\n';
 for(int i=1;i<=n;++i)
  for(int j=1;j<=n;++j)
   if(F[i][j]>0)cout<<i<<' '<<j<<'\n';
}
int main()
{ReadData();
 BuildGraph();
 Flux();
    return 0;
}
