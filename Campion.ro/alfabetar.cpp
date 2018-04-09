#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream f("alfabetar.in");
ofstream g("alfabetar.out");
char a[100][200];
short n;
void citire()
{f>>n;
 f.get();
 for(int i=1;i<=n;i++)f.getline(a[i],200);
}
void afis(char a[100][200])
{int maxi=0;
 for(int i=1;i<=n;i++)
 {int ab=strlen(a[i]);
  if(ab>maxi)maxi=ab;
 }
 for(int j=maxi-1;j>=0;j--)
 {for(int i=1;i<=n;i++)
   if(int(a[i][j]!=0))g<<a[i][j];
   else g<<' ';
  g<<'\n';
 }
}
int main()
{citire();
 afis(a);
    return 0;
}
