#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;
ifstream f("felinare.in");
ofstream g("felinare.out");
std::vector <short> v(5000);
int  d,n;
void c_creare()
{f>>n;
 std::fill(v.begin(),v.begin()+n,1);
 d=n;
}
short val(short c)
{if(c==1)
  {d--;
   return 0;
  }
  d++;
  return 1;
}
int vall(int i)
{if(i==n-1)return -1;
 return i;
}
void rez(short n)
{long long  nr=0;
 for(int i=0;i<n;i++)
 {if(i>0&&v[i-1])v[i]=val(v[i]);
  else
    if(i==0&&v[n-1])v[i]=val(v[i]);
   nr++;
   if(d==n)break;
   i=vall(i);

 }
 g<<nr;
}
int main()
{c_creare();
 rez(n);
 return 0;
}
