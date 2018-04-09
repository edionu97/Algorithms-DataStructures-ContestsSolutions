#include <iostream>
#include <fstream>
#define lengh 20020
using namespace std;
ifstream f("circular.in");
ofstream g("circular.out");
char v[lengh],x[lengh];
int n;
void citire()
{f>>n;
 f.get();
 f.get(v,lengh);
 f.get();
 f.get(x,lengh);
}
int lun[lengh-20],poz[lengh-20];
void pref_suf()
{int k=-1;
 lun[0]=-1;
 for(int i=1;i<n;i++)
 {while(k>=0&&x[k+1]!=x[i])k=lun[k];
  if(x[k+1]==x[i])k++;
  lun[i]=k;
 }
}
void kmp()
{pref_suf();
 int k=-1;
 for(int i=0;i<n;i++)
 {while(k>=0&&x[k+1]!=v[i])k=lun[k];
  if(x[k+1]==v[i])k++;
  poz[i]=k;
 }
}
int verif(int p)
{for(int i=0;i<n;i++)
  if(x[i]!=v[p%n])return -1;
  else p++;
 return 1;
}
void afisare()
{int p=n-poz[n-1]-1;
 if(poz[n-1]==-1)g<<poz[n-1];
 else
 if(verif(p)>0)g<<p;
  else g<<-1;
}
int main()
{citire();
 kmp();
 afisare();
    return 0;
}
