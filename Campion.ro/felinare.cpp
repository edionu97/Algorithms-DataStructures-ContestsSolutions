///http://campion.edu.ro/arhiva/index.php?page=problem&action=view&id=409
#include <fstream>
#include <ctime>
using namespace std;
ifstream f("felinare.in");
ofstream g("felinare.out");
int n;
void citire(int&n)
{f>>n;}
int v[5000];
void creare(int v[5000])
{int i;
 for(i=0;i<n;i++)v[i]=1;
}
void felinare(int n,int v[5000])
{int i,e,p;
 long nr=0;
 for(i=0;i<n;i++)
 {e=0;
  if(i==0)
   if(v[n-1])
     if(v[i]==1)v[i]=0;
     else {v[i]=1;e++;}
  if(i>0)
    if(v[i-1])
     if(v[i]==1)v[i]=0;
     else {v[i]=1;e++;}
  nr++;
 if(e==n)break;
  else
    if(i==n-1)i=-1;
 }
 g<<nr;
}
int main()
{citire(n);
 creare(v);
 felinare(n,v);
 return 0;
}
