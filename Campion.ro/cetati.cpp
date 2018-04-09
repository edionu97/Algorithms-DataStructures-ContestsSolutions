#include <iostream>
#include <cstdio>
#include <utility>
#include <algorithm>
#define NMAX 10010
using namespace std;
pair<long,long>V[NMAX];
int n,poz=1;
void ReadData()
{FILE *fin=fopen("cetati.in","r");
 fscanf(fin,"%d",&n);
  for(int i=1;i<=n;++i)
  {fscanf(fin,"%lld %lld",&V[i].first,&V[i].second);
   if(V[poz]>V[i])poz=i;
  }
 swap(V[1],V[poz]);
}
int Det(pair<long,long>A,pair<long,long>B,pair<long,long>C)
{return ((B.first-A.first)*(C.second-A.second)-(C.first-A.first)*(B.second-A.second));
}
inline bool Cmp(pair<long,long>A,pair<long,long>B)
{return (Det(V[1],A,B)<0);
}
pair<long,long>St[NMAX];
void ConvexHull()
{int top=0;
 St[++top]=V[1];
 St[++top]=V[2];
 for(int i=3;i<=n;++i)
 {while(top>=2&&Det(St[top-1],St[top],V[i])>=0)--top;
  St[++top]=V[i];
 }
 FILE *fout=fopen("cetati.out","w");
 fprintf(fout,"%d",n-top);
 fclose(fout);
}
void Sortare()
{sort(V+2,V+n+1,Cmp);
 ConvexHull();
}
int main()
{ReadData();
Sortare();
    return 0;
}
