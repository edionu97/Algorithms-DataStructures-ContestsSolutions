#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#define NMAX 10006
using namespace std;
char v[40];
vector<int>G[NMAX];
FILE *fin=fopen("program1.in","r");
inline void ReadLine()
{fgets(v,40,fin);}
char Sablon[8][40];
int nrc,n;
void Cuvinte(char x[40])
{nrc=0;
 char *p=strtok(x," \n");
 while(p)
 {strcpy(Sablon[++nrc],p);
  p=strtok(NULL," \n");
 }
}
void Rezolv(int x)
{if(nrc>1)
 for(int i=1;i<=nrc;++i)
   {++i;
    G[x].push_back(atoi(Sablon[i]));
    i+=2;
    if(i<=nrc)G[x].push_back(atoi(Sablon[i]));
    else break;
   }
}
int NrtUnu;
queue<int>Q;
bool viz[NMAX];
void BFS(int i)
{vector<int>::iterator it;
 viz[i]=true;
 NrtUnu++;
 Q.push(i);
 while(!Q.empty())
 {int x=Q.front();
  for(it=G[x].begin();it!=G[x].end();++it)
  if(!viz[*it])
  {viz[*it]=true;
   ++NrtUnu;
   Q.push(*it);
  }
  Q.pop();
 }
}
inline bool AddBound(char x[40],char y[40])
{return !strcmp(x,"EXECUTA\n")&&strcmp(y,".\n");}
void ReadData()
{ReadLine();
 while(strcmp(v,".\n")!=0)
  {char x[40]="";
   strcpy(x,v);
   Cuvinte(v);
   Rezolv(++n);
   ReadLine();
   if(AddBound(x,v))G[n].push_back(n+1);
  }
 fclose(fin);
}
void WriteSol(int p)
{FILE *fout=fopen("program1.out","w");
 fprintf(fout,"%d",p);
 fclose(fout);
}
int main()
{ReadData();
 BFS(1);
 cout<<n;
 WriteSol(NrtUnu);
 return 0;
}
