#include <iostream>
#include <fstream>
#include <algorithm>
#define NMAX 30001
#define ull double
using namespace std;
ifstream f("produs4.in");
ofstream g("produs4.out");
int A[NMAX];
int T;
 
inline bool Cresc(int a,int b)
{
    return a<b;
}
 
inline ull  GetResult(int x[],int n)
{
    double  Pmax=x[1]*x[2]*x[n];
    double Pmax2=x[n-2]*x[n-1]*x[n];
    return max(Pmax,Pmax2);
}
 
void ReadData()
{
    f>>T;
    for(int i=1;i<=T;++i){
        int N;
        f>>N;
            for(int j=1;j<=N;++j)f>>A[j];
        sort(A+1,A+N+1,Cresc);
        g<<GetResult(A,N)<<'\n';
 
    }
}
 
int main()
{
    ReadData();
    return 0;
}