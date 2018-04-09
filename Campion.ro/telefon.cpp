#include <iostream>
#include <vector>
#include <cstdio>
#include <bitset>
#define NMAX 100001
using namespace std;
bitset<NMAX>In;
int Op[NMAX];
int n,m,lant;
void ReadData()
{FILE *fin=fopen("telefon.in","r");
 fscanf(fin,"%d",&n);
 for(int i=1;i<=n;++i)
 {int x;
  fscanf(fin,"%d",&x);
  Op[i]=x;
  In[x]=1;
 }
 fclose(fin);
}
struct Elm
{int B,E;
}Sol[NMAX];
bitset<NMAX>viz;
void Calcul(int x,int lant)
{Sol[lant].B=x;
 Sol[lant].E=x;
 viz[x]=true;
 int p=Op[x];
 while(!viz[p])
 {viz[p]=1;
  Sol[lant].E=p;
  p=Op[p];
 }
}
void Rezolvare(int n)
{for(int i=1;i<=n;++i)
  if(!In[i])Calcul(i,++lant);
 for(int i=1;i<=n;++i)
    if(!viz[i])Calcul(i,++lant);


}
void WriteSol()
{FILE *fout=fopen("telefon.out","w");
 if(lant==1)fprintf(fout,"0");
 else
  {fprintf(fout,"%d\n",lant);
  for(int i=1;i<lant;++i)
  fprintf(fout,"%d %d\n",Sol[i].E,Sol[i+1].B);
  fprintf(fout,"%d %d",Sol[lant].E,Sol[1].B);
  }
  fclose(fout);

}
int main()
{ReadData();
Rezolvare(n);
WriteSol();
 return 0;
}
