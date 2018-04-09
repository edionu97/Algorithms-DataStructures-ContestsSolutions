#include <iostream>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#define NMAX 100001
using namespace std;
FILE *fin=fopen("bacan.in","r");
struct Produse
{char v[50];
 int cant;
}X[1001];
int n;
inline bool Caut(char Vect[],int val)
{int st=1,dr=n;
 while(st<=dr)
 {int mij=(st+dr)/2;
  int cond=strcmp(X[mij].v,Vect);
   if(!cond)
    {X[mij].cant+=val;
     return true;
    }
   else
    if(cond>0)dr=mij-1;
    else st=mij+1;
 }
 return false;
}
inline bool Cresc(Produse A,Produse B)
{return strcmp(A.v,B.v)<0;
}
void Asterisc(char As[],int&val)
{char *p=strchr(As,'*'),Num[4],aux[50]="";
 int poz=p-As,dim=strlen(As);
 strcpy(Num,As+poz+2);
 val=atoi(Num);
 strncpy(aux,As,(poz+1)-2);
 strcpy(As,aux);
}
void ReadData()
{int m;
 fscanf(fin,"%d",&m);
 fgetc(fin);
   for(int i=1;i<=m;++i)
   {char aux[50]="";
    int val;
     fgets(aux,50,fin);
     Asterisc(aux,val);
    if(!Caut(aux,val))
    {strcpy(X[++n].v,aux);
     X[n].cant+=val;
      sort(X+1,X+n+1,Cresc);
    }
   }
}
void WriteSol(int n)
{FILE *fout=fopen("bacan.out","w");
 fprintf(fout,"%d\n",n);
 for(int i=1;i<=n;++i)fprintf(fout,"% s * %d\n",X[i].v,X[i].cant);
 fclose(fout);
}
int main()
{ReadData();
WriteSol(n);
    return 0;
}
