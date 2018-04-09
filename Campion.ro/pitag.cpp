#include <iostream>
#include <fstream>
#include <deque>
using namespace std;
ifstream f("pitag.in");
ofstream g("pitag.out");
long long a;
deque<long long>v;

void rez(long long a)
{long long A=a*a;
 v.push_front(A);
 for(long k=2;k<a;k++)
  if(A%k==0)v.push_front(A/k);

 while(!v.empty())
 {long long val=v.front();
  if((A/val+val)%2==0)
  {long long c=(A/val+val)/2;
   g<<(c-A/val)<<' '<<c<<'\n';
  }
  v.pop_front();}
}
int main()
{f>>a;
 rez(a);
    return 0;
}
