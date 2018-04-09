#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream f("ordonare.in");
ofstream g("ordonare.out");
char text[2010],a[1002][41],ord[29];
int val[100];
void citire()
{f.get(ord,29);
 f.get();
 for(int i=0;i<26;i++)val[ord[i]]=i;
 f.get(text,2010);
}
int maim(int c1,int c2)
{if(c1<c2)return 2;
 if(c1>c2)return 1;
 return -1;
}
int comp(char v[41],char w[41])
{int nr1=strlen(v),nr2=strlen(w);
 if(nr1<nr2)
 {for(int i=0;i<nr1;i++)
   {int c1=val[v[i]],c2=val[w[i]];
    int val=maim(c1,c2);
    if(val>0)return val;
   }
   return 2;
 }
 if(nr2<nr1)
 {for(int i=0;i<nr2;i++)
   {int c1=val[v[i]],c2=val[w[i]];
    int val=maim(c1,c2);
    if(val>0)return val;
   }
   return 1;
 }
 for(int i=0;i<nr1;i++)
   {int c1=val[v[i]],c2=val[w[i]];
    int val=maim(c1,c2);
    if(val>0)return val;
   }
   return 0;
}
void separare(int&n)
{n=0;
 char *p=strtok(text,",.;?:! ");
 while(p)
 {strcpy(a[++n],p);
  p=strtok(NULL,",.;?:! ");
 }
}
int poz(int li,int ls)
{bool ok=0;
 while(li<ls)
 {if(comp(a[li],a[ls])==1)
   {char aux[42]="";
    strcpy(aux,a[li]);
     strcpy(a[li],a[ls]);
     strcpy(a[ls],aux);
     ok=!ok;
   }
  if(!ok)li++;
  else ls--;
 }
 return li;
}
void ordo(int li,int ls)
{if(li<ls)
  {int p=poz(li,ls);
   ordo(li,p-1);
   ordo(p+1,ls);
  }
}
void afisare()
{int n;
 separare(n);
 ordo(1,n);
 for(int i=1;i<n;i++)g<<a[i]<<' ';
 g<<a[n]<<'\n';
}
int main()
{citire();
afisare();
    return 0;
}
