#include <iostream>
#include <fstream>
using namespace std;
ifstream f("maroco.in");
ofstream g("maroco.out");
int n;
long long SI,SG;
struct betisor
{short ord,nre,p,k,bete[101];
}a[101],aux;
void citire()
{f>>n;
 for(int i=1;i<=n;i++)
 {f>>a[i].p>>a[i].nre;
  a[i].k=i;
  for(int j=1;j<=a[i].nre;j++)f>>a[i].bete[j];
 }
}
int poz(int li,int ls)
{bool ok=0;
 while(li<ls)
 {if(a[li].p<a[ls].p)
    {aux=a[li];
     a[li]=a[ls];
     a[ls]=aux;
     if(ok)ok=0;
     else ok=1;
    }
 if(!ok)li++;
 else ls--;
 }
 return li;
}
void quick(int li,int ls)
{if(li<ls)
  {int p=poz(li,ls);
   quick(li,p-1);
   quick(p+1,ls);
  }
}
bool fol[1001];
bool verif(int i)
{int m=a[i].nre;
 for(int j=1;j<=m;j++)
  if(!fol[a[i].bete[j]])return 0;
 return 1;
}
void greedy(int n)
{int ok=0,ordi=1;
 do
 {ok=0;
  for(int i=1;i<=n;i++)
     if(!fol[a[i].k]&&verif(i))
     {if(ordi==1)
       {ordi=2;
        SI+=a[i].p;
       }
      else
      {ordi=1;
       SG+=a[i].p;
      }
      ok=1;
      fol[a[i].k]=1;
      break;
     }
 }while(ok);
 if(SI>SG)g<<1<<' '<<SI;
 else
 if(SI<SG)g<<2<<' '<<SG;
 else g<<0<<' '<<SI;
}
int main()
{citire();
 quick(1,n);
 greedy(n);
    return 0;
}
