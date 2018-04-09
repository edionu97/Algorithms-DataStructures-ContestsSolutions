#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
ifstream f("dartz.in");
ofstream g("dartz.out");
long long S;
void citire()
{f>>S;
 S/=2;
}
double radical_3(double nr)
{return pow(nr,1.0/3);}
void rez(long long S)
{long long A=floor(radical_3(S)),B=A+1,C=B+1,ok=1;
 while(ok)
  {if(A*B*C>S){A--,B--,C--;}
   else
   {A--,B--,C--;
     long long D=S-A*B*C;
    long long E=floor(radical_3(D));
    if(E*(E+1)*(E+2)==D)
    {g<<E<<' '<<A<<' '<<E<<' '<<A;
     break;
    }
    else
      if((E-1)*E*(E+1)==D)
       {g<<E-1<<' '<<A<<' '<<E-1<<' '<<A;
        break;
       }
  }
  }

}
int main()
{citire();
 //cout<<radical_3(S);
 rez(S);
    return 0;
}
