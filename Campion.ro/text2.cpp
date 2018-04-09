#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream f("text2.in");
ofstream g("text2.out");
int poz[1020],n,m,maxi;
char v[1020];
void citire()
{f>>n;
 f.get();
 f.get(v,1001);
 for(int i=97;i<=122;i++)poz[char(i)]=i-97;
}
char a[1002][256];
void sep()
{char *p;
m=1;
 p=strtok(v,"*");
 while(p)
 {strcpy(a[m],p);
  int lung=strlen(a[m]);
  for(int j=0;j<lung;j++)
  {int nr=1;
   while(poz[a[m][j]]<poz[a[m][j+1]]&&j+1<=lung-1)
   {nr++;
    j++;
   }
   if(nr>1)j--;
   maxi=max(maxi,nr);
  }
  p=strtok(NULL,"*");
  m++;
 }
}
void nrs(int m)
{int nrs=0,y[501],o=0,lung;
 for(int i=1;i<=m;i++)
  {int maxi2=0;
   lung=strlen(a[i]);
   for(int j=0;j<lung;j++)
    {int nr=1;
     while(poz[a[i][j]]<poz[a[i][j+1]]&&j+1<=lung-1)
     {nr++;
      j++;
    }
   if(nr>1)j--;
   maxi2=max(maxi2,nr);
   if(maxi2==maxi)
   {y[++o]=i;
    nrs++;
    break;
   }
  }
}
g<<nrs<<'\n';
for(int i=1;i<=o;i++)g<<y[i]<<' ';
g<<endl;
}
int fol[1000];
void cuv(int m)
{for(int i=1;i<=m;i++)
 {int lung=strlen(a[i]);
  for(int j=0;j<lung;j++)fol[a[i][j]]=1;
 }
}
int main()
{citire();
 sep();
 nrs(m);
 cuv(m);
 int nr=0;
 for(int i='a';i<='z';i++)
    if(fol[i])nr++;
g<<nr;
    return 0;
}
