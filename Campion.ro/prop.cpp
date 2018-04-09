//verif daca se poate construi cuv de lugime j<=k
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream f("prop.in");
ofstream g("prop.out");
char pr[251][257];
int n,k;
void citire()
{f>>n>>k;
 f.get();
 for(int i=1;i<=n;i++)f.getline(pr[i],257);
 if(n>1)k=k-(n-1);
}
short dim[256][502];
struct cuv
{char b[129][257];
}a[256];
short d[256];
void sep(int i)
{char *p=strtok(pr[i]," ");
 int elem=0;
 while(p)
 {strcpy(a[i].b[++elem],p);
  dim[i][elem]=strlen(a[i].b[elem]);
  p=strtok(NULL," ");
 }
 d[i]=elem;
}
bool fol[265][260];
short l[256][501],scrie[265][501],muta[265][501],p[265];
void trunch(int n)
{for(int i=1;i<=n;i++)sep(i);}

void afis(int i,int j)
{if(i!=1)afis(i-1,muta[i][j]);
 if(i==1)g<<a[i].b[j]<<' ';
 else
if(i!=n)g<<a[i].b[scrie[i][j]]<<' ';
else g<<a[i].b[scrie[i][j]];
}

void cont_pd(int n)
{for(int i=3;i<=n;i++)
  for(int m=1;m<=d[i];m++)
   if(!fol[i][dim[i][m]])
    {for(int j=dim[i][m]+1;j<=k;j++)
     if(!l[i][j]&&l[i-1][j-dim[i][m]])
      if(l[i-1][j-dim[i][m]]+dim[i][m]<=k)
    {l[i][j]=l[i-1][j-dim[i][m]]+dim[i][m];
     scrie[i][j]=m;
     muta[i][j]=l[i-1][j-dim[i][m]];
    }
    else break;
    fol[i][dim[i][m]]=1;
    }
 if(l[n][k])afis(n,k);
 else g<<0;
}

void p_d(int n)
{if(n==1)
 {int i;
  for(i=1;i<=d[1];i++)
  if(dim[1][i]==k){g<<a[1].b[i];break;}
  if(i>d[1])g<<0;
 }
 else
 {for(int i=1;i<=d[1];i++)
  if(dim[1][i]<=k&&!fol[1][dim[1][i]])
  {l[1][dim[1][i]]=dim[1][i];
   fol[1][dim[1][i]]=1;
   p[dim[1][i]]=i;
  }

  for(int i=1;i<=d[2];i++)
  if(!fol[2][dim[2][i]])
  {for(int j=dim[2][i]+1;j<=k;j++)
     if(l[1][j-dim[2][i]]&&!l[2][j])
    if(l[1][j-dim[2][i]]+dim[2][i]<=k)
    {l[2][j]=l[1][j-dim[2][i]]+dim[2][i];
     scrie[2][j]=i;
     muta[2][j]=p[j-dim[2][i]];
    }
    else break;
    fol[2][dim[2][i]]=1;
    }
    if(n==2&&l[2][k])afis(2,k);
    else
     if(n==2)g<<0;
     else cont_pd(n);
 }
}
int main()
{citire();
 trunch(n);
 p_d(n);
    return 0;
}
