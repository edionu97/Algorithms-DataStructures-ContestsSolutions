#include <iostream>
#include <cstdio>
#include <vector>
#define ull unsigned long long
#define NMAX 50001
using namespace std;
vector<ull>Sume;
ull Update[NMAX];
int n,m;
int Binary_Search(ull val,int nr)
{int st=1,dr=n,mij;
 while(st<=dr)
 {mij=(st+dr)/2;
  ull l1=Sume[mij-1]+Update[mij-1]*nr;
  ull l2=Sume[mij]+Update[mij]*nr;
  if(val<=l2&&val>=l1)
   if(val==l1)return mij-1;
   else
    if(val==l2)return mij;
  else return mij-1;
  else
    if((Sume[mij]+Update[mij]*nr)>val)dr=mij-1;
    else st=mij+1;
 }
 return 0;
}
void ReadData()
{FILE *fin=fopen("miere.in","r");
 fscanf(fin,"%d",&n);
 ull x;
 fscanf(fin,"%lld",&x);
 Update[0]=1;
 for(int i=1;i<=n;++i)Update[i]=i;
 Update[n+1]=n;
 Sume.push_back(0);
 Sume.push_back(x);
 int s=x;
    for(int i=2;i<=n;++i)
    {fscanf(fin,"%lld",&x);
        Sume.push_back(Sume[i-1]+x);
    }
 Sume.push_back(Sume[n]+1);
  fscanf(fin,"%d",&m);
 FILE *fout=fopen("miere.out","w");
 for(int i=1;i<=m;++i)
 {fscanf(fin,"%lld",&x);
  int val=Binary_Search(x,i-1);
  if(val==0&&Sume[n]<x)fprintf(fout,"%d\n",n);
   else
  fprintf(fout,"%d\n",val);
 }
}
int main()
{ReadData();
 return 0;
}
