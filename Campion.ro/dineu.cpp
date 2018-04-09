#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>
#define NMAX 100
using namespace std;
vector<int>G[NMAX];
int n,l;
void ReadData()
{FILE *fin=fopen("dineu.in","r");
 fscanf(fin,"%d %d",&n,&l);
 for(int i=1;i<=n;++i)
 {int nrl;
  fscanf(fin,"%d",&nrl);
   for(int j=1;j<=nrl;++j)
   {int x;
    fscanf(fin,"%d",&x);
    G[i+20].push_back(x);
    G[x].push_back(i+20);
   }
 }
 fclose(fin);
}
bitset<NMAX>Dr[NMAX];
void IsDrum()
{for(int i=1;i<=n;++i)
 {vector<int>::iterator it,it1;
  for(it=G[i+20].begin();it!=G[i+20].end();++it)
     for(it1=G[*it].begin();it1!=G[*it].end();++it1)
        if(i+20!=*it1)Dr[i+20][*it1]=Dr[*it1][i+20]=1;
 }
}
int Sol[NMAX];
inline bool cond(int k)
{for(int i=1;i<k;++i)
  if(!Dr[Sol[k]][Sol[i]]||Sol[k]<=Sol[i])return 0;
 return 1;
}
int maxi,SolG[NMAX];
void Back(int k)
{for(int i=1;i<=n;++i)
  {Sol[k]=i+20;
   if(cond(k))
   {Back(k+1);
    if(maxi<k)
    {maxi=k;
     for(int i=1;i<=k;++i)SolG[i]=Sol[i];
    }
   }
  }
}
void WriteSol()
{FILE *fout=fopen("dineu.out","w");
 fprintf(fout,"%d\n",maxi);
 for(int i=1;i<=maxi;++i)
 {int val;
  val=max(SolG[i]/10-2,0)*10+SolG[i]%10;
  fprintf(fout,"%d ",val);
 }
 fclose(fout);
}
int main()
{ReadData();
 IsDrum();
 Back(1);
 WriteSol();
    return 0;
}
