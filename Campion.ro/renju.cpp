#include <iostream>
#include <fstream>
using namespace std;
ifstream f("renju.in");
ofstream g("renju.out");
short a[20][20];
void citire()
{for(int i=1;i<=19;i++)
  for(int j=1;j<=19;j++)f>>a[i][j];
}
int nr1,nr2,l1,c1;
void st(short i)
{int aux,j=1;
 do
 {aux=j;
  while(a[i][j]==a[i][j+1]&&j+1<=19)j++;
  if(j-aux==4&&a[i][j])
  {l1=i;c1=aux;
   if(a[i][j]==1){nr1=1;break;}
   else {nr2=2;break;}
  }
  else j++;
 }while(j<=19);
}
void dp(short i)
{short j=1,aux1,aux2;
 do
  {aux1=i,aux2=j;
   while(a[i][j]==a[i+1][j+1]&&i+1<=19)
   {i++;
    j++;
   }
   if(j-aux2==4&&a[aux1][aux2])
   {l1=aux1;c1=aux2;
     if(a[aux1][aux2]==1){nr1=1;break;}
     else {nr2=2;break;}
   }
   else
   {i++;
    j++;
   }
  }while(i<=19&&j<=19);
}
void sus_j(short j)
{short  i=1,aux;
 do
 {aux=i;
  while(a[i][j]==a[i+1][j]&&i+1<=19)i++;
  if(i-aux==4&&a[aux][j])
  {l1=aux;c1=j;
   if(a[i][j]==1){nr1=1;break;}
   else {nr2=2;break;}
  }
  else i++;
 }while(i<=19);
}
void ds(short j)
{short i=1,aux1,aux2;
 do
 {aux1=i,aux2=j;
  while(a[i][j]==a[i+1][j-1]&&i+1<=19&&j-1>=1)
  {i++;
   j--;
  }
  if(i-aux1==4&&aux2-j==4&&a[aux1][aux2])
  {l1=i;c1=j;
     if(a[i][j]==1){nr1=1;break;}
     else {nr2=2;break;}
  }
  else
  {i++;
   j--;
  }
 }while(i<=19&&j>=1);
}
void rez()
{bool sc=0;
 int i=1,j=1;
 for(i=1;i<=19;i++)st(i);
  if(nr1==0&&nr2==0)
  for(j=1;j<=19;j++)sus_j(j);
  if(nr1==0&&nr2==0)
    for(i=1;i<=15;i++)dp(i);
    if(nr1==0&&nr2==0)
  for(j=5;j<=19;j++)ds(j);
 if(nr1!=0||nr2!=0)
  {g<<max(nr1,nr2)<<'\n';
   g<<l1<<' '<<c1;
   sc=1;
  }
 if(!sc)g<<0;
}
int main()
{citire();
 rez();
    return 0;
}
