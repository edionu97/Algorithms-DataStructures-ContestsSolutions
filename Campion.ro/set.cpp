#include <iostream>
#include <vector>
#include <fstream>
#define lengh 1005
using namespace std;
ifstream f("set.in");
ofstream g("set.out");
int A[lengh],B[lengh],lung;
long long n,dim1,dim2;
void citire()
{f>>n;}
void produs(int&dim1,int dim2)
{std::vector <bool>fol(lengh);
 std::vector <int>p(lengh);
 std::fill(p.begin(),p.begin()+dim1+dim2+1,0);
 std::fill(fol.begin(),fol.end(),0);
 lung=0;
 int i,j;
 for(i=1;i<=dim1;i++)
 {int rest=0;
  for(j=1;j<=dim2;j++)
  {rest+=A[i]*B[j]+p[i+j-1];
  if(!fol[i+j-1])
   {lung++;
    fol[i+j-1]=1;
   }
   p[i+j-1]=rest%10;
   rest/=10;
  }
  if(rest)
  {if(!fol[i+j-1])
   {lung++;
    fol[i+j-1]=1;
   }
   p[i+j-1]=rest;
  }
 }
 for(int i=1;i<=lung;i++)A[i]=p[i];
 dim1=lung;
}
void afisare (long long n)
{int dim1=0,dim2=0;
 if(n==1)g<<0<<endl<<0;
 long long  c=n+1,a=n,b=n-1;
 while(a)
 {A[++dim1]=a%10;
  a/=10;
 }
 while(b)
 {B[++dim2]=b%10;
  b/=10;
 }
 produs(dim1,dim2);
 dim2=0;
 for(int i=dim1;i>=1;i--)g<<A[i];
 g<<'\n';
 while(c)
 {B[++dim2]=c%10;
  c/=10;
 }
 produs(dim1,dim2);
  for(int i=dim1;i>=1;i--)g<<A[i];
}
int main()
{citire();
 afisare(n);
    return 0;
}
