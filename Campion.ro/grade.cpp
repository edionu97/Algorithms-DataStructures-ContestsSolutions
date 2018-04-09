#include <cstdio>
#include <vector>
#include <queue>
#define NMAX 5001
using namespace std;
priority_queue<int>H;
int n;
void ReadData()
{FILE *fin=fopen("grade.in","r");
 fscanf(fin,"%d",&n);
 for(int i=1;i<=n;++i)
 {int x;
  fscanf(fin,"%d",&x);
  H.push(x);
 }
 fclose(fin);
}
int Leg[NMAX];
class Comp
{public:
 bool operator ()(int x,int y)
 {return Leg[x]<Leg[y];
 }
};
queue<int>Q;
priority_queue<int,vector<int>,Comp>H2,H3;
vector<int>G[NMAX];
void MakeGraph()
{int i=0;
 while(!H.empty())
 {Leg[++i]=H.top();
  H2.push(i);
  H.pop();
 }
 H3.push(1);
 H2.pop();
 while(!H3.empty()&&!H2.empty())
 {int x=H3.top();
  H3.pop();
  while(Leg[x]&&!H2.empty())
  {int y=H2.top();
   --Leg[x];
   --Leg[y];
   G[x].push_back(y);
   if(Leg[y])H3.push(y);
   H2.pop();
  }
  if(Leg[x])H3.push(x);
 }
 while(!H3.empty())
 {int x=H3.top();
  H3.pop();
  while(Leg[x]&&!H3.empty())
  {int y=H3.top();
   H3.pop();
   --Leg[x];
   --Leg[y];
   G[x].push_back(y);
   Q.push(y);
  }
  while(!Q.empty())
  {H3.push(Q.front());
   Q.pop();
  }
 }
}
void WriteSol()
{FILE *fout=fopen("grade.out","w");
 for(int i=1;i<=n;++i)
  for(vector<int>::iterator it=G[i].begin();it!=G[i].end();++it)fprintf(fout,"%d %d\n",i,*it);
fclose(fout);
}
int main()
{ReadData();
 MakeGraph();
 WriteSol();
 return 0;
}
