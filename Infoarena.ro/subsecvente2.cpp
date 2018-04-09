#include <iostream>
#include <cstdio>
#include <cstring>
#define NMAX 50001
using namespace std;
FILE *fin=fopen("subsecvente2.in","r");
FILE *fout=fopen("subsecvente2.out","w");
char a[5][NMAX];
int n;
void ReadData()
{fscanf(fin,"%d",&n);
 fgetc(fin);
 for(int i=1;i<=n;++i)fgets(a[i],NMAX,fin);
 fclose(fin);
}
struct nod
{char ch;
 int s;
 nod *st,*dr;
}*rad;
inline void Add(nod *&p,char c)
{p=new nod;
 p->ch=c,p->s=1;
 p->st=p->dr=NULL;
}
void BuildTree(nod *rad,int i,int maxlengh)
{if(a[1][i]=='a')
 {if(rad->st==NULL)Add(rad->st,a[1][i]);
  if(i+1<maxlengh)BuildTree(rad->st,i+1,maxlengh);
 }
 else
 {if(rad->dr==NULL)Add(rad->dr,a[1][i]);
  if(i+1<maxlengh)BuildTree(rad->dr,i+1,maxlengh);
 }
}
void InsertSubsecvences()
{rad=new nod;
 rad->st=rad->dr=NULL;
 rad->ch='R';
 int maxlengh=strlen(a[1])-1;
 for(int i=0;i<maxlengh;++i)BuildTree(rad,i,min(60+i,maxlengh));
}
int maxG,nc;
void GetLongest(nod *rad,int i,int maxlengh,int S)
{if((S-rad->s)>1)return;
 if(a[S][i]=='a')
 {if(rad->st==NULL||(S-rad->st->s)>1)return;
  rad->s=rad->st->s=S;
  if(i+1<maxlengh)GetLongest(rad->st,i+1,maxlengh,S);
  else return;
 }
 else
 {if(rad->dr==NULL || (S-rad->dr->s)>1 )return;
  rad->s=rad->dr->s=S;
  if(i+1<maxlengh)GetLongest(rad->dr,i+1,maxlengh,S);
  else return;
 }
}
void Solve()
{int ant=1;
 for(int k=2;k<=n;++k,maxG=nc=1)
  {int maxlengh=strlen(a[k])-1;
    for(int i=0;i<maxlengh-1;++i,nc=1)
    GetLongest((a[k][i]=='a' ? rad->st : rad->dr),i+1,min(60+i,maxlengh),k);
  }
}
void RSD(nod*rad,int k)
{if(rad!=NULL && rad->s==n)
 {RSD(rad->st,k+1);
   maxG=max(k,maxG);
  RSD(rad->dr,k+1);
   maxG=max(k,maxG);
 }
}
int main()
{ReadData();
InsertSubsecvences();
Solve();
RSD(rad->st,1);
RSD(rad->dr,1);
fprintf(fout,"%d",maxG);
    return 0;
}