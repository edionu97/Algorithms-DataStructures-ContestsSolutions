#include <iostream>
#include <fstream>
using namespace std;
ifstream f("sudoku.in");
ofstream g("sudoku.out");
struct BestPoz
{int b[10],nre;
}v[10];

int a[10][10],ok,lev[10],n;
void ReadData()
{for(int i=1;i<=9;i++)
 {for(int j=1;j<=9;j++)
  {char ch;
   f>>ch;
   a[i][j]=int(ch)-48;
   if(!a[i][j])v[i].b[++v[i].nre]=j;
  }
  if(v[i].nre)lev[++n]=i;
 }
}

int l[10][10],c[10][10],z[10][10];
int zn(int val)
{if(val>=1&&val<=3)return 1;
 else
 if(val>=4&&val<=6)return 2;
 return 3;
}

int okk(int val,int niv)
{if(niv>=1&&niv<=3)return zn(val);
 else
 if(niv>=4&&niv<=6)return 3+zn(val);
  return 6+zn(val);
}

void Constrang()
{for(int i=1;i<=9;i++)
 for(int j=1;j<=9;j++)
 {int val=a[i][j];
  if(val)l[i][val]=c[val][j]=1;
 }
}

void RestrictieZona()
{for(int i=1;i<=9;i++)
 for(int j=1;j<=9;j++)
 {int zone=okk(j,i);
  z[zone][a[i][j]]=1;
 }
}

void SolveSudoku(int k,int niv)
{int p=lev[niv];
 if(niv==n+1)ok=1;
 else
  for(int i=1;i<=9&&!ok;i++)
  {int val=v[p].b[k];
   int zon=okk(val,p);
   if(!l[p][i]&&!c[i][val]&&!z[zon][i])
   {a[p][val]=i;
    l[p][i]=c[i][val]=z[zon][i]=1;
    if(k<v[p].nre)SolveSudoku(k+1,niv);
    else SolveSudoku(1,niv+1);
    if(!ok)l[p][i]=c[i][val]=z[zon][i]=0;
   }
  }
}
void Write()
{for(int i=1;i<=9;i++)
 {for(int j=1;j<=9;j++)g<<a[i][j];
  g<<'\n';
 }
}
int main()
{ReadData();
Constrang();
RestrictieZona();
SolveSudoku(1,1);
Write();
    return 0;
}
