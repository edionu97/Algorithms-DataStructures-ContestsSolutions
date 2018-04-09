#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream f("clase.in");
ofstream g("clase.out");
char a[1400][260];
int n=1;
void citire()
{while(f.getline(a[n],300))++n;}

struct fr
{int lt[40];
}cu[1400];
int poz(int li,int ls)
{bool ok=0;
 while(li<ls)
 {if(strcmp(a[li],a[ls])>0)
  {char aux[251]="";
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
bool fol[251];
void quick(int li,int ls)
{if(li<ls)
 {int p=poz(li,ls);
  quick(li,p-1);
  quick(p+1,ls);
 }
}
void frec(int n)
{for(int i=1;i<=n;i++)
  {int m=strlen(a[i]);
   for(int j=0;j<m;j++)cu[i].lt[a[i][j]]++;
     while(!strcmp(a[i],a[i+1])&&i+1<=n){fol[i+1]=1;i++;}
  }
}
struct afis
{int cuv[250];
 int dim;
}clase[500];
void afisare(int n)
{for(int i=1;i<=n;i++)
   {for(int j=1;j<clase[i].dim;j++)g<<a[clase[i].cuv[j]]<<' ';
    g<<a[clase[i].cuv[clase[i].dim]];
    if(i<n)g<<'\n';
   }
}
void solve(int n)
{int nrc=1;
 for(int i=1;i<=n;i++)
   if(!fol[i])
   {int mm=strlen(a[i]);
    clase[nrc].cuv[1]=i;
    int nr=1;
    for(int j=i+1;j<=n;j++)
     if(!fol[j])
     {int m=strlen(a[j]);
      int ok=0;
      if(mm==m)
      {for(char c='a';c<='z';c++)
         if(cu[i].lt[c]!=cu[j].lt[c]){ok=1;break;}
        if(!ok){
      clase[nrc].cuv[++nr]=j;
      fol[j]=1;}
      }
     }
   clase [nrc++].dim=nr;
   }
   afisare(nrc-1);
}

int main()
{citire();
 quick(1,n-1);
 frec(n);
 solve(n);

    return 0;
}
