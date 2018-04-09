#include <fstream>
#include <iostream>
using namespace std;
ifstream f("anagramabil.in");
ofstream g("anagramabil.out");
long long n;
struct elemente
{short v[10];
}elem[11];
void citire()
{f>>n;
 long long aux=n;
 while(aux)
 {elem[1].v[aux%10]++;
  aux/=10;
 }
}
bool anagram(long long x,int j)
{while(x)
 {elem[j].v[x%10]++;
  x/=10;
 }
 for(int i=0;i<=9;i++)
    if(elem[1].v[i]!=0&&elem[j].v[i]!=elem[1].v[i]||elem[1].v[i]==0&&elem[j].v[i]!=elem[1].v[i])return 0;
 return 1;
}
void gen_num(long long n)
{int j=2;
 bool ok=1,ok1=0;
 for(int i=2;i<=9;i++)
  {if(anagram(n*i,j))
   if(ok==1&&ok1==0)
   {g<<"DA"<<'\n';
    g<<i;
    ok=0;
   }
   else g<<i;
   j++;
  }
if(ok==1&&ok1==0)g<<"NU";
}
int main()
{citire();
 gen_num(n);
    return 0;
}
