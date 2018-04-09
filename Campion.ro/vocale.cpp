#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <set>
#define oo 2000000051
#define NMAX 256
using namespace std;
ifstream f("vocale.in");
int n;
char Prop[NMAX];
class comp
{public :
  bool operator() (string A,string B)
  {return A<B;
  }
};
FILE *fout=fopen("vocale.out","w");
int val[251][260],glob=1;
set<string,comp>S;
void Cuv(char V[NMAX],int i)
{int mini=oo;
 set<string,comp>::iterator it;
 char *p=strtok(V," "),*scrie;
 while(p)
 {char v[NMAX]="";
   strcpy(v,p);
  int m=strlen(v),nr=0;
    for(int i=0;i<m;++i)
        if(strchr("aeiou",v[i]))++nr;
      it=S.find(p);
    if(it==S.end())
     {S.insert(p);
      if(mini==nr)++val[i][mini];
        else
         if(mini>nr)
          {mini=nr;
           scrie=p;
           val[i][mini]=1;
          }
     }
  p=strtok(NULL," ");
 }
 fprintf(fout,"%s ",scrie);
 glob=glob*val[i][mini];
 glob=glob%2003;
 S.clear();
}
void ReadData()
{f>>n;
 f.get();
 for(int i=1;i<=n;++i)
 {f.getline(Prop,NMAX);
  Cuv(Prop,i);
 }
}
int main()
{ReadData();
fprintf(fout,"\n%d",glob);
    return 0;
}
