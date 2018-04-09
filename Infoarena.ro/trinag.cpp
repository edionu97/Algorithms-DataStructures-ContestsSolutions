#include <iostream>
#include <algorithm>
#include <cstdio>
#include <utility>
#include <vector>
#include <cmath>
#define x first
#define y second
#define precision 0.001
using namespace std;
 
class Cmp{
public:
    bool operator()(pair<double,double>A,pair<double,double>B){
        return A.x<B.x;
    }
};
 
class Triang{
private:
    FILE *fin,*fout;
    vector< pair <double,double > > Points;
    int N;
    double modul(double x){
        return (x>0 ? x :-x);
    }
    bool Binary_Search(int poz,pair<double,double>P){
        int st=poz,dr=N,mij;
        while(st<=dr){
            mij=(st+dr)/2;
            if( modul(P.x-Points[mij].x) <= precision && modul(P.y-Points[mij].y) <= precision)return true;
                else
                    if(Points[mij].x-P.x>=precision)dr=mij-1;
                        else
                            st=mij+1;
        }
        return false;
    }
 
    pair <double,double> NeededPoint60( pair<double,double>A,pair<double,double>B,double Sin60,double Cos60){
        return make_pair(A.x+(B.x-A.x)*Cos60-(B.y-A.y)*Sin60,A.y+(B.x-A.x)*Sin60+(B.y-A.y)*Cos60);
    }
 
    pair<double,double> NeededPoint300(pair<double,double>A,pair<double,double>B,double Sin300,double Cos300){
        return make_pair(A.x+(B.x-A.x)*Cos300-(B.y-A.y)*Sin300,A.y+(B.x-A.x)*Sin300+(B.y-A.y)*Cos300);
    }
 
public:
    Triang(){
        fin=fopen("triang.in","r");
        fout=fopen("triang.out","w");
    }
    void ReadData(){
        fscanf(fin,"%d",&N);
        Points.push_back(make_pair(0,0));
        for(int i=1;i<=N;++i){
            double x,y;
            fscanf(fin,"%lf %lf",&x,&y);
            Points.push_back( make_pair(x,y) );
        }
        sort(Points.begin()+1,Points.end(),Cmp());
    }
    void GetNumberOfPioints(){
        int Nrt=0;
        for(int i=1;i<=N;i++)
            for(int j=i+1;j<=N;++j){
            Nrt+=Binary_Search(j+1,NeededPoint60(Points[i],Points[j],(double)sqrt(3)/2,0.5));
            Nrt+=Binary_Search(j+1,NeededPoint300(Points[i],Points[j],-(double)sqrt(3)/2,0.5));
        }
        fprintf(fout,"%d",Nrt);
    }
}Ob;
 
int main()
{
    Ob.ReadData();
    Ob.GetNumberOfPioints();
    return 0;
}