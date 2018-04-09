#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;
int T[55][55],n,c,d,A[55][55][22],maxig;
void ReadData()
{FILE *fin=fopen("cuburi2.in","r");
 fscanf(fin,"%d %d %d",&n,&c,&d);
 for(int i=1;i<=c;++i)
 {int x,y,t;
  fscanf(fin,"%d %d %d",&x,&y,&t);
  ++T[x][y];
  maxig=max(maxig,T[x][y]);
  A[x][y][T[x][y]]=t;
 }
 fclose(fin);
}
FILE *fout=fopen("cuburi2.out","w");
int L[51][51];
struct Elm
{int l,c,val;
};
inline bool Crescendo(Elm B,Elm C)
{return B.val>C.val;
}
vector<Elm>Sol[55];
bitset<25>Uz[55];
void BuildLeftVector()
{for(int i=1;i<=n;++i)
   {for(int j=1;j<=n;++j)
     if(!Uz[i][T[i][j]]&&T[i][j])
     {Elm B;
      B.l=i,B.c=j,B.val=T[i][j];
      Sol[i].push_back(B);
      Uz[i][T[i][j]]=true;
     }
     sort(Sol[i].begin(),Sol[i].end(),Crescendo);
   }
}
void BuildLeftImage()
{int p=0,k=0;
 for(int i=1;i<=n;++i)
   if(Sol[i].size())
    {p=k=0;
     for(int j=maxig-Sol[i][0].val+1;j<=maxig;++j)
      {L[j][i]=A[Sol[i][k].l][Sol[i][k].c][T[Sol[i][k].l][Sol[i][k].c]--];
       if(Sol[i].size()>p+1)
        if(T[Sol[i][k].l][Sol[i][k].c]==Sol[i][p+1].val)
             if(Sol[i][k].c>Sol[i][p+1].c)k=++p;
              else ++p;
      }
    }
 }
void Write()
{fprintf(fout,"%d %d\n",maxig,n);
  for(int i=1;i<=maxig;++i)
    {for(int j=1;j<=n;++j)fprintf(fout,"%d ",L[i][j]);
     fprintf(fout,"\n");
    }
}
void BuildFrontVector()
{ for(int j=1;j<=n;++j)
   {for(int i=n;i>=1;--i)
    if(!Uz[j][T[i][j]]&&T[i][j])
      {Elm B;
       B.l=i,B.c=j,B.val=T[i][j];
       Sol[j].push_back(B);
       Uz[j][T[i][j]]=true;
      }
      sort(Sol[j].begin(),Sol[j].end(),Crescendo);
   }
}
void BuildFrontImage()
{int i=1,p,k;
 for(int i=1;i<=n;++i)
  if(Sol[i].size())
   {p=0,k=0;
    for(int j=maxig-Sol[i][0].val+1;j<=maxig;++j)
    {L[j][i]=A[Sol[i][k].l][Sol[i][k].c][T[Sol[i][k].l][Sol[i][k].c]--];
     if(Sol[i].size()>p+1)
        if(T[Sol[i][k].l][Sol[i][k].c]==Sol[i][p+1].val)
             if(Sol[i][k].l<Sol[i][p+1].l)k=++p;
              else ++p;}
   }
}
int main()
{ReadData();
  switch(d)
  {case 1:
    {fprintf(fout,"%d %d\n",n,n);
     for(int i=1;i<=n;++i)
      {for(int j=1;j<=n;++j)
       if(!T[i][j])fprintf(fout,"%d ",0);
        else fprintf(fout,"%d ",A[i][j][T[i][j]]);
        fprintf(fout,"\n");
      }
      break;
    }
   case 2:{BuildLeftVector();BuildLeftImage();Write();break;}
   case 3:{BuildFrontVector();BuildFrontImage();Write();break;}
  }
 fclose(fout);
 return 0;
}
