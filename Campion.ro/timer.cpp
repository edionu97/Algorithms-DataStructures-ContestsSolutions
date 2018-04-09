#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;
ifstream f("timer.in");
ofstream g("timer.out");
char ora[100],sun[100];
long A,B,C,D,E,F,n,m,t;
void citire()
{f.get(ora,100);
 n=strlen(ora);
 f.get();
 f.get(sun,100);
 m=strlen(sun);
}
void schimb(long a,long b,long c,long p)
{switch (p)
 {case 2:{A=0,C=b;B=a;break;}
  case 1:{C=a;A=B=0;break;}
 }
}
void ad()
{int curs=0,p=0;
 for(int i=0;i<m;i++)
 {char aux[10]="";
   short j=0;
   curs++;
   while(sun[i]!=':'&&i<m)aux[j++]=sun[i++];
   p++;
    switch (curs)
    {case 1:{A=atol(aux);break;}
     case 2:{B=atol(aux);break;}
     case 3:{C=atol(aux);break;}
    }
 }
 schimb(A,B,C,p);
}
void conv(long n,long m)
{short curs=0;
 for(int i=0;i<n;i++)
  {char aux[10]="";
   short j=0;
   curs++;
   while(ora[i]!=':'&&i<n)aux[j++]=ora[i++];
   switch (curs)
    {case 1:{D=atol(aux);break;}
     case 2:{E=atol(aux);break;}
     case 3:{F=atol(aux);break;}
    }
  }
  ad();
}
void solv(long A,long B,long C)
{F+=C;
 E+=B;
 D+=A;
 t=F/60;
 F=F-t*60;
 E+=t;
 t=E/60;
 E=E-t*60;
 D+=t;
 t=D/24;
 D=D-t*24;
}
void afis(long D,long E,long F,long t)
{if(D==0)g<<"00:";
 else
  if(D<10)g<<'0'<<D<<':';
  else g<<D<<':';

 if(E==0)g<<"00:";
 else
  if(E<10)g<<'0'<<E<<':';
 else g<<E<<':';

 if(F==0)g<<"00";
 else
    if(F<10)g<<'0'<<F;
 else g<<F;
 if(t!=0)g<<'+'<<t;
}
int main()
{citire();
 conv(n,m);
 solv(A,B,C);
 afis(D,E,F,t);
    return 0;
}
