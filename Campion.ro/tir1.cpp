#include <algorithm>
#include <iostream>
#include <bitset>
#include <cstdio>
#include <stack>
#define NMAX 1001
using namespace std;
int n,k;
int v[51],S[NMAX],El[NMAX],Leg[NMAX];
void ReadData()
{FILE *fin=fopen("tir1.in","r");
 fscanf(fin,"%d %d",&n,&k);
 for(int i=1;i<=n;++i)fscanf(fin,"%d",&v[i]);
 fclose(fin);
}
inline bool Cresc(int a,int b)
{return a<b;}
void Pd(int n)
{sort(v+1,v+n+1,Cresc);
 for(int i=1;i<=n;++i)
  for(int j=v[i];j<=k;++j)
     if(j==v[i])
      {S[j]=1;
        El[j]=v[i];
         Leg[j]=0;
      }
    else
     if(S[j-v[i]]&&(S[j-v[i]]+1<S[j]||!S[j]))
     {S[j]=S[j-v[i]]+1;
      El[j]=v[i];
      Leg[j]=j-v[i];
     }
}
stack<int>St;
void Write()
{FILE*fout=fopen("tir1.out","w");
 //cout<<S[k];
if(!S[k])fprintf(fout,"%d",0);
else
 {fprintf(fout,"%d\n",S[k]);
    int p=k;
    while(p)
    {St.push(El[p]);
    p=Leg[p];
    }
    while(!St.empty())
    {fprintf(fout,"%d ",St.top());
    St.pop();
    }
    fclose(fout);
 }
}
int main()
{ReadData();
 Pd(n);
Write();
    return 0;
}
