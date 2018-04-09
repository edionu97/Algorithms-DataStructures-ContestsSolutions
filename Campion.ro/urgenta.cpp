#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <cstdio>
#define NMAX 257
using namespace std;
struct Muc
{int x,y,z;
};
class Comp
{public:
 bool operator()(Muc X,Muc Y)
 {return X.z>Y.z;
 }
};
priority_queue<Muc,vector<Muc>,Comp>H;
int n,m,k;
void ReadData()
{FILE *fin=fopen("urgenta.in","r");
 fscanf(fin,"%d %d %d",&n,&m,&k);
  for(int i=1;i<=m;++i)
  {Muc val;
   fscanf(fin,"%d %d %d",&val.x,&val.y,&val.z);
   H.push(val);
  }
  fclose(fin);
}
int T[NMAX];
vector< pair<int,int> >Sol;
class Apm
{public:
  bool operator()(Muc X,Muc Y)
  {return X.z<Y.z;
  }
};
priority_queue<Muc,vector<Muc>,Apm>A;
int MaxSol;
void APM()
{int Nrm=1;
 for(int i=1;i<=n;++i)T[i]=i;
 while(Nrm<n)
  {Muc val=H.top();
   H.pop();
   if(T[val.x]!=T[val.y])
   {++Nrm;
    A.push(val);
    int Up=T[val.y];
     for(int i=1;i<=n;++i)
      if(T[i]==Up)T[i]=T[val.x];
   }
   else
   {Sol.push_back(make_pair(val.x,val.y));
    MaxSol+=val.z;
   }
  }
 while(!H.empty())
 {Muc val=H.top();
  MaxSol+=val.z;
  Sol.push_back(make_pair(val.x,val.y));
  H.pop();
 }
}
void Calculate()
{APM();
while(k-1)
 {Muc val=A.top();
 MaxSol+=val.z;
  Sol.push_back(make_pair(val.x,val.y));
 A.pop();
  --k;
 }
}
void WriteSol()
{FILE *fout=fopen("urgenta.out","w");
 fprintf(fout,"%d\n%d\n",MaxSol,Sol.size());
 vector< pair<int,int> >::iterator it;
 for(it=Sol.begin();it!=Sol.end();++it)fprintf(fout,"%d %d\n",it->first,it->second);
 fclose(fout);
}
int main()
{ReadData();
 Calculate();
 WriteSol();
    return 0;
}
