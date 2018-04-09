#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream f("nrcuv.in");
ofstream g("nrcuv.out");
char v[256]="";
void citire()
{f.get(v,255);
}
char cuv[256][256];
int elm=0;
void sep()
{char *p=strtok(v," ,!?.");
 while(p)
 {strcpy(cuv[++elm],p);
  p=strtok(NULL," ,!?.");
 }
}
bool verif(char vec[])
{int m=strlen(v);
 for(int i=0;i<m;i++)
  if(vec[i]>='a'&&vec[i]<='z'||vec[i]>='A'&&vec[i]<='Z')return 1;
 return 0;
}
void calcul(int elm)
{int nr=0;
 for(int i=1;i<=elm;i++)
  if(verif(cuv[i]))nr++;
 g<<nr;
}
int main()
{citire();
 sep();
 calcul(elm);
    return 0;
}
