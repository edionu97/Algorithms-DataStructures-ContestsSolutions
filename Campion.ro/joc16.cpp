#include <fstream>
#define lengh 40001
using namespace std;
ifstream f("joc16.in");
ofstream g("joc16.out");
int b[lengh],n,x,y,r[lengh];
void citire()
{f>>n>>x>>y;}
void sect(int n,int x,int y)
{int i=1,j=1,s=0,t=0;
 b[1]=r[1]=1;
 bool ok=1;
 while(ok)
 {if(i+x>n)i=x-(n-i);
  else i=i+x;
  if(j-y<1)j=n-y+j;
  else j=j-y;
  b[i]++;
  r[j]++;
  s++;
  if(b[i]>1||r[j]>1||i==j)break;
 }
 for(int c=1;c<=n;c++)
  if(b[c]==0&&r[c]==0)t++;
 g<<t<<' '<<s<<' '<<i<<' '<<j;
}
int main()
{citire();
 sect(n,x,y);
    return 0;
}
