#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#define NMAX 2000020
using namespace std;
 
class KMP{
private:
    char sir1[NMAX],sir2[NMAX];
    FILE *fin,*fout;
    int m,n;
    int Next[NMAX];
    vector <int> GetPositions;
    void SufPref(){
        memset(Next,0,sizeof(Next));
        int k=0;
        for(int i=1;i<m;++i){
            while(k && sir1[i]!=sir1[k])k=Next[k-1];
            if(sir1[i]==sir1[k])++k;
            Next[i]=k;
        }
    }
public:
    KMP(){
        fin=fopen("strmatch.in","r");
        fout=fopen("strmatch.out","w");
    }
    void ReadStrings(){
        fgets(sir1,NMAX,fin);
        fgets(sir2,NMAX,fin);
        m=strlen(sir1)-1,n=strlen(sir2)-1;
        sir1[m]=sir2[n]=NULL;
    }
    void KmpAlgorithm();
    void WriteSolution();
}Ob;
 
void KMP::KmpAlgorithm()
{
    SufPref();
    int index=0;
    for(int i=0;i<n;++i){
        while(index && sir1[index]!=sir2[i])index=Next[index-1];
        if(sir2[i]==sir1[index])++index;
        if(index==m){
            GetPositions.push_back(i-index+1);
            index=Next[index-1];
        }
    }
}
 
void KMP::WriteSolution()
{
    int N=(int)GetPositions.size();
    fprintf(fout,"%d\n",N);
    for(int i=0;i<min(N,1000);++i)
        fprintf(fout,"%d ",GetPositions[i]);
}
 
 
int main()
{
    Ob.ReadStrings();
    Ob.KmpAlgorithm();
    Ob.WriteSolution();
    return 0;
}