#include <iostream>
#include <fstream>
#include <cmath>
#include <deque>
using namespace std;
ifstream f("tan.in");
ofstream g("tan.out");
unsigned long long  x;
short fol[10],nrc,folp;
void cifrare(unsigned long long  x)
{while(x)
 {++nrc;
  fol[x%10]++;
  if((x%10)%2==0)folp++;
  x/=10;
 }
}
deque<int> v;
int nr[20];
void calcul()
{bool ok=0;
 for(int i=1;i<=9;i++)
  if(fol[i])
   if(i%2==0&&folp-1>0)
   {v.push_front(i);
    fol[i]--;
    folp--;
    break;
   }
   else
    if(i%2!=0)
   {v.push_front(i);
    fol[i]--;
    break;
   }
 do
 {for(int i=0;i<=9;i++)
  if(fol[i])
    if(i%2==0&&folp-1>0)
    {v.push_back(i);
     folp--;
      fol[i]--;
      break;
    }
    else
     if(i%2!=0)
     {fol[i]--;
      v.push_back(i);
      break;
     }
 }while(v.size()+1<nrc);
 for(int i=0;i<=9;i+=2)
    if(fol[i])
 {v.push_back(i);
  break;
 }
}
int main()
{f>>x;
cifrare(x);
 calcul();
  while(!v.empty())
 {g<<v.front();
  v.pop_front();
 }
    return 0;
}
