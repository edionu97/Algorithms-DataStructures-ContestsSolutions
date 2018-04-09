#include <iostream>
#include <fstream>
#define ull unsigned long long
using namespace std;
ifstream f("divizori.in");
ofstream g("divizori.out");
int m,k;
ull H=1;

inline long long expl(long long a,int exp)
{
    if(exp==0)return 1;
    if(exp % 2 == 0)return expl(a*a,exp/2);
    else return a*expl(a*a,exp/2);
}

int Put[51];

void Desc(int x)
{
    int d=2,nr;
    do
    {
        nr=0;
        while(x%d==0){
            ++nr;
            x/=d;
        }
        if(nr)Put[d]=max(Put[d],nr);
        ++d;
    }while(x>1);
}

void Calcul()
{
    for(int i=k+1;i<m;++i)Desc(i);
    for(int i=2;i<=50;++i)
        if(Put[i])H*=expl(i,Put[i]);
}

inline ull GetNumber(ull H)
{
    for(int i=1;;++i){
        ull N=i*H+k;
        if(N%m==0)return N;
    }

}
int main()
{
    f>>m>>k;
    Calcul();
    g<<GetNumber(H);
    return 0;
}
