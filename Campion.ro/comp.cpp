#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
using namespace std;
ifstream f("comp.in");
ofstream g("comp.out");
char v[256]="";
short n,nrs;
bool sol[1001];
void calc(char vv[],long long&nr)
{char *p=strtok(vv,"+");
 char mat[256][256];
 int m=0;
 while(p)
 {strcpy(mat[++m],p);
  p=strtok(NULL,"+");
 }
 long long mii=0,sute=0,zeci=0,unit=0;
 for(int i=1;i<=m;i++)
 {int l=strlen(mat[i]),j=0;
  mii=sute=zeci=unit=0;
  for(int j=0;j<l;j++)
   {char numar[10]="";
    int dim=-1;
    while(mat[i][j]>='0'&&mat[i][j]<='9'&&j<l)numar[++dim]=mat[i][j++];
    switch(mat[i][j])
      {case 'm':{mii+=atoi(numar);break;}
       case 's':{sute+=atoi(numar);break;}
       case 'z':{zeci+=atoi(numar);break;}
       case 'u':{unit+=atoi(numar);break;}
      }
   }
  nr+=mii*1000+sute*100+zeci*10+unit;
 }
}
bool val(int ok,long long nr1,long long nr2)
{if(ok&&nr1>nr2||ok==1&&nr1==nr2)return 0;
 if(!ok&&nr1<nr2||!ok&&nr1==nr2)return 0;
 return 1;
}
void rezolv(char v[],bool ok)
{long long nr1=0,nr2=0;
 char *p,*d;
 p=strtok(v,"><");
 d=strtok(NULL,"<>");
 calc(p,nr1);
 calc(d,nr2);
 sol[++nrs]=val(ok,nr1,nr2);
}
void citire()
{f>>n;
int nrc=0;
 for(int i=1;i<=n;i++)
 {f.get();
  f.get(v,256);
  if(strchr(v,'<'))
  {rezolv(v,1);nrc++;}
  else rezolv(v,0);
 }
 g<<nrc<<'\n';
}
void afis(short nrs)
{for(int i=1;i<=nrs;i++)g<<sol[i]<<'\n';}
int main()
{citire();
 afis(nrs);
    return 0;
}
