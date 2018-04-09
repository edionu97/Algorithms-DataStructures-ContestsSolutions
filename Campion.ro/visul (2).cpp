#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
ifstream f("visul.in");
ofstream g("visul.out");
long long  n,p[33];
int v[]={0,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
void atr()
{p[1]=1,p[2]=5,p[3]=7,p[4]=9;
 p[5]=12,p[6]=14,p[7]=16,p[8]=19,p[9]=21;
}
void citire()
{f>>n;
 atr();
}
void sv(long long&nr)
{int elem=1,poz=n;
 do
 {nr=nr*10+v[p[poz]]%10;
  p[poz]++;
  poz=nr%10;
  elem++;
 }while(elem!=n);
}
void rez(long long n)
{if(n==10||n==1)g<<-1;
 else
 {sv(n);
  g<<n;
 }
}
int main()
{citire();
 rez(n);
}
