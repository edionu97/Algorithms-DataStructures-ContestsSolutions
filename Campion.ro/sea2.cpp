#include <iostream>
#include <set>
#include <utility>
#include <cstdio>
using namespace std;
class Comp
{public:
  bool operator()(pair<int,int>A,pair<int,int>B)
  {return A<B;
  }
};
set<pair<int,int>,Comp>myset;
int n;
void ReadData()
{FILE *fin=fopen("sea2.in","r");
 FILE *fout=fopen("sea2.out","w");
 fscanf(fin,"%d",&n);
 pair<int,int>P;
 fscanf(fin,"%d %d",&P.first,&P.second);
 myset.insert(P);
 set<pair<int,int>,Comp>::iterator it,it1;
 fprintf(fout,"1\n");
 for(int i=2;i<=n;++i)
    {fscanf(fin,"%d %d",&P.first,&P.second);
     it=myset.upper_bound(P);
     if(it!=myset.end()&&it->second>P.second)fprintf(fout,"-1\n");
     else
     {it1=it;
      --it1;
       while(it1!=myset.begin())
       {if(it1->second>P.second)break;
         --it1;
       }
       if(it1->second<P.second)myset.erase(it1,it);
       else myset.erase(++it1,it);
       myset.insert(P);
      fprintf(fout,"%d\n",myset.size());
     }
    }
}
int main()
{ReadData();
 return 0;
}
