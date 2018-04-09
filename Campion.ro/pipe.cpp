#include <iostream>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <queue>
#define NMAX 29001
using namespace std;
int n,s1,s2,xa,ya,xb,yb,j;
bitset<NMAX>SumeA,SumeR;
class MinHeap
{public:
  bool operator()(int a,int b)
  {return a>b;
  }
};
priority_queue<int,vector<int>,MinHeap>H1,H2;
void ReadData()
{FILE *fin=fopen("pipe.in","r");
  fscanf(fin,"%d %d %d %d %d",&n,&xa,&ya,&xb,&yb);
  SumeA[0]=SumeR[0]=1;
  fgetc(fin);
   for(int i=1;i<=n;++i)
    {char type=NULL;
        int lengh=0;
        fscanf(fin,"%c %d",&type,&lengh);
            fgetc(fin);
          if(type=='A')H1.push(lengh);
        else H2.push(lengh);
    }
fclose(fin);
}
inline double modul(double a)
{return abs(a);
}
int rez;
void Sums()
{FILE *fout=fopen("pipe.out","w");
 while(!H1.empty())
 {int val=H1.top();
  H1.pop();
  for(s1+=val,j=val;j<=s1;++j)
     if(SumeA[j-val])SumeA[j]=true;
 }
 while(!H2.empty())
 {int val=H2.top();
  H2.pop();
  for(s2+=val,j=val;j<=s2;++j)
     if(SumeR[j-val])SumeR[j]=true;
 }
}
void WriteSol()
{FILE *fout=fopen("pipe.out","w");
 int d1=modul(xa-xb),d2=modul(ya-yb);
 if(SumeA[d1]&&SumeR[d2])fprintf(fout,"%d",d1+d2);
 else
  {bool ok=false;
    for(j=0;j<=s1;++j)
     if(SumeA[j+d1]&&SumeA[j])
     {ok=true;
      rez+=(2*j+d1);
      break;
     }
     if(!ok)fprintf(fout,"imposibil");
      else
        {ok=false;
        for(j=0;j<=s1;++j)
            if(SumeR[j+d2]&&SumeR[j])
            {ok=true;
            rez+=(2*j+d2);
            break;
            }
       if(!ok)fprintf(fout,"imposibil");
       else fprintf(fout,"%d",rez);
    }
  }
}
int main()
{ReadData();
Sums();
 WriteSol();
    return 0;
}
