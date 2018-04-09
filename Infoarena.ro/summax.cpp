#include <iostream>
#include <cstdio>
#include <vector>
#define NMAX 2001
#define NRMAX 2000000001
#define NCHAR 1000002
using namespace std;
FILE *fout;
 
class Input_Reader{
private:
    FILE *in;
    char buffer[NCHAR];
    int PozInBuffer,endoffile;
    void Advance(){
        if(PozInBuffer+1==NCHAR){
            PozInBuffer=-1;
            fread(buffer,1,NCHAR,in);
            endoffile=feof(in);
        }
        ++PozInBuffer;
    }
    inline bool IsFigure(char val){
        return (val>='0' && val <='9');
    }
public:
    Input_Reader (char *p,char* type){
        in=fopen(p,type);
        fread(buffer,1,NCHAR,in);
        PozInBuffer=endoffile=0;
    }
    Input_Reader &operator >> (long &number){
        number=0;
        while(!IsFigure( buffer[PozInBuffer] ))Advance();
        while(IsFigure(buffer[PozInBuffer])){
            number=number*10+buffer[PozInBuffer]-'0';
            Advance();
        }
        return *this;
    }
    bool eof(){
        return endoffile;
    }
}fin("summax.in","r");
 
class Prob{
private:
    long a[NMAX][NMAX+1];
    long N,st,dr,v,nrd;
    int Drum[NMAX];
    long Min(unsigned long long A,unsigned long long B){
        return ((A<B) ? A : B);
    }
    inline void Write(){
        for(int i=1;i<=N;++i)
            fprintf(fout,"%d ",Drum[i]);
        fprintf(fout,"\n");
    }
    void BuildMatrix(){
        for(int i=N-1;i>=1;--i){
            for(int j=1;j<=i;++j)
                if(a[i+1][j]>a[i+1][j+1]){
                    a[i][j]=Min(a[i][j]+a[i+1][j],NRMAX);
                    a[j][i+1]=1;
                }else
                    if(a[i+1][j]<a[i+1][j+1]){
                        a[i][j]=Min(a[i][j]+a[i+1][j+1],NRMAX);
                        a[j][i+1]=2;
                    }else{
                        a[i][j]=Min(a[i][j]+a[i+1][j+1],NRMAX);
                        a[j][i+1]=3;
                    }
        }
        for(int i=1;i<=N;++i)a[N][i]=1;
        for(int j=N;j>=2;--j)
            for(int i=1;i<j;++i){
                switch(a[i][j]){
                    case 1:{a[j-1][i]=Min(a[j][i],NRMAX);break;}
                    case 2:{a[j-1][i]=Min(a[j][i+1],NRMAX);break;}
                    case 3:{a[j-1][i]=Min(a[j][i]+a[j][i+1],NRMAX);break;}
                }
            }
    }
 
    void WriteRoads(int line,int col){
        if(nrd>dr)return;
        if(nrd+a[line][col]<st && line>1){
            nrd+=a[line][col];
            return;
        }
        Drum[line]=col;
        if(line==N){
            ++nrd;
            Write();
        }
        else
            switch(a[col][line+1]){
                case 1:{
                    WriteRoads(line+1,col);
                    if(nrd==dr)return;
                    break;
                }
                case 2:{
                    WriteRoads(line+1,col+1);
                    if(nrd==dr)return;
                    break;
                }
                case 3:{
                    WriteRoads(line+1,col);
                    if(nrd==dr)return;
                    WriteRoads(line+1,col+1);
                }
            }
    }
public:
    Prob(){
        fout=fopen("summax.out","w");
        nrd=0;
    }
    void ReadData(){
        fin>>v>>N>>st>>dr;
        for(int i=1;i<=N;++i)
            for(int j=1;j<=i;++j)fin>>a[i][j];
    }
 
    void Solve(){
        BuildMatrix();
        if(v==1){
            fprintf(fout,"%li",a[1][1]);
            return;
        }
        WriteRoads(1,1);
    }
}Ob;
 
int main(){
   Ob.ReadData();
   Ob.Solve();
    return 0;
}
© 2004-2018 Asociatia infoarenaPrima paginaDespre infoarenaTermeni si conditiiContactSari la inceputul paginii ↑
Creative Commons License Cu exceptia cazurilor in care se specifica altfel, continutul site-ului infoarena
este publicat sub licenta Creative Commons Attributio