#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <algorithm>
using namespace std;
ifstream f("reziston.in");
ofstream g("reziston.out");
char v[1020];
int n,dim=0;
int desc[1010],inc[1010];
void citire()
{f.get(v,1010);
 n=strlen(v);
 int j=0,p[1010],k=0;
 for(int i=0;i<n;i++)
  if(v[i]=='(')
  {desc[++j]=i;
   p[j]=i;
   k=0;
  }
  else
   if(v[i]==')')
   {inc[p[j]]=i;
    p[j]=p[j-1];
    p[j-1]=p[j-2-k];
    k++;
   }
   dim=j;
}
void scad(int k,int descr)
{for(int j=k;j>=1;j--)
  if(inc[desc[j]]>inc[desc[k+1]])inc[desc[j]]-=descr;
}
void calcul(char vv[1010],long&val)
{long pp=1,st=0,s,m,nre;
 char*p;
 p=strtok(vv,",)");
 while(p)
 {char b[1010]="";
  strcpy(b,p);
  m=strlen(b);
  s=0;
  for(int i=0;i<m;i++)
  {nre=0;
   char c[3]="";
   while(b[i]>='0'&&b[i]<='9'&&i<m)c[nre++]=b[i++];
   if(nre)
   {s+=atoi(c);
    i--;}
  }
  if(s)
  {pp*=s;
   st+=s;
  }
  p=strtok(NULL,",)");
 }
 if(pp==st)val=pp;
 else
    if(st)val=pp/st;
     else val=0;
}
void rez1(int k)
{if(k<dim)rez1(k+1);
 char vec[1010]="",nr[11]="";
 int in=desc[k]+1,lung=0;
 int decrem=(inc[desc[k]]-desc[k]-1);
 long val;
 strncpy(vec,v+in,decrem);
 calcul(vec,val);
 int i=1;
 while(val)
 {nr[i++]=48+val%10;
 val/=10;
 }
reverse(nr+1,nr+i);
 nr[0]='R';
 lung=strlen(nr);
 for(int i=0;i<lung;i++)v[in-1+i]=nr[i];
 strcpy(v+in-1+lung,v+inc[desc[k]]+1);
 scad(k-1,decrem+2-lung);
}
int main()
{long val;
 citire();
 if(dim)rez1(1);
 calcul(v,val);
  g<<val;
return 0;
}
