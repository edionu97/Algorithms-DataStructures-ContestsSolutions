#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream f("fraze.in");
ofstream g("fraze.out");
char a[102][258];
int n;
void citire(){
while(f.getline(a[++n],300));
n--;
}
int vec[102][101],nrp,nrpp;
char pan[102][258];
int poz(int li,int ls)
{bool ok=0;
 while(li<ls)
 {if(strcmp(pan[li],pan[ls])==1)
   {char aux[300]="";
    strcpy(aux,pan[li]);
    strcpy(pan[li],pan[ls]);
    strcpy(pan[ls],aux);
    ok=!ok;
   }
  if(!ok)li++;
  else ls--;
 }
 return li;
}
void ord(int li,int ls)
{if(li<ls)
 {int p=poz(li,ls);
  ord(li,p-1);
  ord(p+1,ls);
 }
}
void numarare_pan(int n)
{int dim=0;
 for(int i=1;i<=n;i++)
 {int m=strlen(a[i]);
  for(int j=0;j<m;j++)
  {char ch=a[i][j];
   if(ch!=' '&&ch!=',')
    if(ch>='A'&&ch<='Z')vec[i][ch+32]++;
    else vec[i][ch]++;
  }
  bool ok=1,ok1=1;
  for(int k='a';k<='z';k++)
    if(!vec[i][k])ok=0;
     else
        if(vec[i][k]>1)ok1=0;
  if(ok){nrp++;strcpy(pan[++dim],a[i]); if(ok1)nrpp++;}

 }
 ord(1,dim);
 g<<nrp<<' '<<nrpp<<'\n';
 if(nrp)
 {for(int i=1;i<dim;i++)g<<pan[i]<<endl;
  g<<pan[dim];
 }
}
int main()
{citire();
 numarare_pan(n);
    return 0;
}
