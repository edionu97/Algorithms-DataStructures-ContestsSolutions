#include <fstream>
#include <cstring>
#include <iostream>
#define maxn 100001
using namespace std;
ifstream f("compar.in");
ofstream g("compar.out");
char v[1][maxn];
int x[maxn],n;
void citire()
{f.getline(v[1],maxn-1);
}
void rezolvare(int x[maxn])
{g<<strlen(v[1])+1<<endl;
 int i;
 long p=strlen(v[1])+2,d=0,n=strlen(v[1]);
 for(i=0;i<n;++i)
  if(v[1][i]=='>')
  {g<<--p<<" ";
   if(v[1][i+1]=='>')
    while(v[1][i+1]=='>'){i++;g<<--p<<" ";}
  }
  else
  {g<<++d<<" ";
   if(v[1][i+1]=='<')
   while(v[1][i+1]=='<'){i++;g<<++d<<" ";}
  }
  if(v[1][i-1]=='<')g<<++d;
 else g<<--p;
}
int main()
{citire();
 rezolvare(x);
 return 0;
}
