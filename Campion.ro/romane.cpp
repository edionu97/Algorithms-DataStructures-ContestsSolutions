#include <fstream>
#include <iostream>
using namespace std;
ifstream f("romane.in");
ofstream g("romane.out");
int n,x[6];
void citire()
{f>>n;}
void prel(int c,int nr)
{switch(nr)
 {case 1:{
     if(c<5){x[1]++;x[2]++;}
     if(c>5){x[1]++;x[3]++;}
     break;}
  case 2:
     {switch(c)
      {case 4:{x[3]++;x[4]++;break;}
       case 9:{x[5]++;x[3]++;break;}
      }
       break;
     }
 }
}
void prel2(int c,int nr)
{switch(nr)
 {case 1:{
      if(c<5)
       while(c)
       {x[1]++;
        c--;
       }
      else
      {x[2]++;
       c-=5;
       while(c)
       {x[1]++;
        c--;
       }
      }

       break;
     }
    case 2:
     {if(c==1)x[3]++;
      else
       if(c<=3)
      while(c)
      {x[3]++;
       c--;
      }
      else
        if(c>=5)
      {x[4]++;
       c-=5;
       while(c)
       {x[3]++;
        c--;
       }
      }
      break;
     }
    case 3:
        {while(c)
         {x[5]++;
          c--;
         }
         break;
        }
 }
}
void sol(int i)
{int nr=1;
 while(i!=0)
 {if(i%10==4||i%10==9)prel(i%10,nr);
  else
    if(i%10!=0)prel2(i%10,nr);
  nr++;
  i/=10;
 }
}
void rom(int n)
{for(int i=1;i<=n;i++)sol(i);
 g<<x[1]<<' '<<x[2]<<' '<<x[3]<<' '<<x[4]<<' '<<x[5]<<endl;
}
int main()
{citire();
rom(n);
return 0;
}
