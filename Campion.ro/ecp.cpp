#include <iostream>
#include <fstream>
#include <cstring>
#define NMAX 1001
using namespace std;
ifstream f("ecp.in");
ofstream g("ecp.out");
int n;
char Ecp[NMAX];

void ReadData()
{
    f.get(Ecp,NMAX);
    n=strlen(Ecp);
}

struct Stack{
    char ch;
    bool ok;
};

Stack S[NMAX];
int top;

inline void Push(char val)
{
    ++top;
    S[top].ch=val;
    S[top].ok=0;
}

inline void Pop()
{
    --top;
}

inline char Close(char val)
{
    switch(val){
        case '(' :{return ')';break;}
        case '{' :{return '}';break;}
        case '[' :{return ']';break;}
    }
}

int v[15];

inline int GetCost(char val)
{
    if(val=='(')return 2;
    else
        if(val=='[')return 3;
        else
            return 5;
}

inline void Calculate(char ch,int poz)
{
    if(S[poz].ok==1)
        v[GetCost(ch)]+=GetCost(ch);
    else ++v[GetCost(ch)];

}

inline void Solve()
{
    for(int i=0;i<n;++i){
        Push(Ecp[i]);
        if(Close(S[top-1].ch)==Ecp[i]){
            Calculate(S[top-1].ch,top-1);
            Pop();Pop();
            S[top].ok=1;
        }
    }
}

void Write()
{
    g<<v[2]<<' '<<v[3]<<' '<<v[5];
}

int main()
{
    ReadData();
    Solve();
    Write();
    return 0;
}
