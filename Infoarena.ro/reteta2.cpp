#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;
ifstream f("reteta2.in");
ofstream g("reteta2.out");
char v[1000];
int  n,m;
struct ing
{char nume[21];
 long val;
}x[500];
void citire()
{f.get(v,1000);
 n=strlen(v);
}
void timp(char v[1000])
{long num=0;
 for(int i=0;i<n;i++)
     if(v[i]==')')
     {while(int(v[i])<48||int(v[i])>57&&i+1<n){i++;v[i-1]=' ';}
      char nr[3]="";
      int p=0;
      while(int(v[i])>=48&&int(v[i])<=57&&i<n){nr[p++]=v[i++];v[i-1]=' ';}
      num+=atoi(nr);
      i--;
     }
     else
        if(v[i]=='(')v[i]=' ';
 g<<num<<'\n';
}
char a[1002][22];
void sep()
{char *p;
 p=strtok(v," ");
 while(p)
 {strcpy(a[++m],p);
  p=strtok(NULL," ");
 }
 int lim=0;
 for(int i=1;i<=m;i+=2)
 {strcpy(x[++lim].nume,a[i]);
  x[lim].val=atoi(a[i+1]);
 }
m=lim;
}
int poz(int li,int ls)
{int ok=0;
 while(li<ls)
 {if(strcmp(x[li].nume,x[ls].nume)>0)
   {ing aux;
    aux=x[li];
    x[li]=x[ls];
    x[ls]=aux;
    if(ok)ok=0;
    else ok=1;
   }
   if(!ok)li++;
   else ls--;
 }
return li;
}
void sortare(int li,int ls)
{if(li<ls)
 {int p=poz(li,ls);
  sortare(li,p-1);
  sortare(p+1,ls);
 }
}
void afisare(int m)
{for(int i=1;i<=m;i++)
 {long nr=x[i].val;
  while(!strcmp(x[i].nume,x[i+1].nume)&&i+1<=m)nr+=x[i+1].val,i++;
  g<<x[i].nume<<' '<<nr<<'\n';
 }
}
int main()
{citire();
 timp(v);
 sep();
 sortare(1,m);
afisare(m);
  return 0;
}