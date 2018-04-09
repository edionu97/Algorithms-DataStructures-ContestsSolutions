///http://campion.edu.ro/arhiva/index.php?page=problem&action=view&id=837
#include <fstream>
using namespace std;
ifstream f("desen2.in");
ofstream g("desen2.out");
int l,L;
void citire(int &l,int&L)
{f>>l;
 f>>L;
}
void nrmax(int l,int L)
{int ok=0,s=0,s1=0,nr=0,nr1=0;
 while(!ok)
 {s=s+L;
  nr++;
  if(s%l==0)ok=1;
 }
 while(s!=s1)
 {s1=s1+l;
  nr1++;
 }
g<<s<<endl;
g<<nr1*nr;
}
int main()
{citire(l,L);
 nrmax(l,L);
 return 0;
}
