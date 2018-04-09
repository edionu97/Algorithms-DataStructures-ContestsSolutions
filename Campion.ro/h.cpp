#include <iostream>
#include <fstream>
#define lengh 50001
using namespace std;
ifstream f("h.in");
ofstream g("h.out");
unsigned x[lengh],v[lengh];
long long sum1,sum2,n;
void citire()
{f>>n;
 int i=1;
 for(i=1;i<=2*n;i++)x[i]=i;
 for(int j=1;j<=2*n;j++)v[j]=i++;
 sum1=(2*n*(2*n+1))/2;
 sum2=(4*n*(4*n+1))/2-sum1;
}
void stef(long long sum1,long long sum2)
{int i=1;
 while(sum1!=sum2)
 {sum1=sum1+v[i]-x[i];
  sum2=sum2+x[i]-v[i];
  v[i]=x[i++];
 }
 for(int i=1;i<=2*n;i++)g<<v[i]<<' ';
}
int main()
{citire();
 stef(sum1,sum2);
 return 0;
}
