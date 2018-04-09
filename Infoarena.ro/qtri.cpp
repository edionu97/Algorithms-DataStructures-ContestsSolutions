#include <iostream>
#include <cstdio>
#include <utility>
#include <cmath>
#define x first
#define y second
#define Point pair<double,double>
using namespace std;
FILE *fin = fopen("qtri.in","r");
FILE *fout = fopen("qtri.out","w");
 
class Problema{
private:
    pair<double,double>A,B,C,D;
    int N;
 
    inline double GetArie(Point A,Point B,Point C){
        return (B.x - A.x) * (C.y - A.y) - (C.x-A.x) * (B.y-A.y);
    }
public:
 
    void Query(){
        fscanf(fin,"%d",&N);
        while(N--){
            fscanf(fin,"%lf %lf %lf %lf %lf %lf %lf %lf",&A.x,&A.y,&B.x,&B.y,&C.x,&C.y,&D.x,&D.y);
            if(abs(GetArie(A,B,C)) == abs(GetArie(A,D,C)) + abs(GetArie(A,D,B)) + abs(GetArie(B,C,D))){
                fprintf(fout,"DA\n");
                continue;
            }
            fprintf(fout,"NU\n");
        }
    }
}P;
 
int main()
{
    P.Query();
    return 0;
}