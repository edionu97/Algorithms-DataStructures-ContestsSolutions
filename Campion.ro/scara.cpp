#include <fstream>
using namespace std;
ifstream f("magic6.in");
ofstream g("magic6.out");
char v[1001];
int n,x[9];
void citire()
{f>>n;
 for(int i=0;i<n;i++)f>>v[i];
}
void caractere(int n)
{for(int i=0;i<n;i++)
 if(v[i]>='a'&&v[i]<='z')g<<char(v[i]-32);
 else x[v[i]-48]=1;
 g<<'\n';
}
void funct(int&i)
{int j;
 for(j=i+1;j<=9;j++)
 if(x[j]==1){g<<j;break;}
 i=j;
}
void numar(int x[9])
{bool ok=1;
 int i;
for(i=0;i<=9;i++)
 if(i==0&&ok==1&&x[i]==1)
 {int aux=i;
  funct(i);
  g<<aux;
  ok=0;}
 else
 if(x[i]==1)g<<i;
}
int main()
{citire();
 caractere(n);
 numar(x);
    return 0;
}
