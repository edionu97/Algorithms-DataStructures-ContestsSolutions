#include <cstdio>
#include <bitset>
#define NMAX 100001
 
using namespace std;
 
int Nr;
bitset  < NMAX  > IsInFront;
 
void ReadAndSolve() {
    FILE *fin = fopen("sortare2.in", "r");
    int N;
    fscanf(fin, "%d", &N);
    while (N--) {
        int x;
        fscanf(fin, "%d", &x);
        if (!IsInFront[x - 1]) ++Nr;
        IsInFront[x] = 1;
    }
    fclose(fin);
}
 
inline void Write() {
    FILE * fout = fopen("sortare2.out", "w");
    fprintf(fout, "%d", --Nr);
    fclose(fout);
}
 
int main(){
    ReadAndSolve();
    Write();
    return 0;
}