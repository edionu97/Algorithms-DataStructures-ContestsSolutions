#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#define NMAX_WORD 2001
#define NMAX 200001
using namespace std;
 
class Trie{
private:
    struct TRIE{
        int index;
        TRIE *Sons[27];
        TRIE(){
            index=0;
            memset(Sons,0,sizeof(Sons));
        }
    };
    int Fol[NMAX],NrCuvTrie;
    void DfsTrie(TRIE * rad,int niv){
        Fol[rad->index]=true;
        Niv[rad->index]=niv;
        Euleriana[++DimEuler]=rad->index;
        First[rad->index]=DimEuler;
        for(int i=0;i<=26;++i){
            if(rad->Sons[i]==NULL)continue;
            if(!rad->Sons[i]->index)rad->Sons[i]->index=++NrCuvTrie;
            if(!Fol[rad->Sons[i]->index]){
                    DfsTrie(rad->Sons[i],niv+1);
                    Euleriana[++DimEuler]=rad->index;
            }
        }
    }
protected:
    int Coliziune[NMAX],First[NMAX],Niv[NMAX],Euleriana[2*NMAX],DimEuler;
public:
    TRIE *root;
    Trie(){
      root=new TRIE;
      NrCuvTrie=DimEuler=0;
      memset(Fol,0,sizeof(Fol));
    }
    void AddInTrie(char *p,int index,TRIE *rad){
        if(*p=='\n'){
            if(!rad->index){
                Coliziune[index]=index;
                rad->index=index;
                ++NrCuvTrie;
            }
            else
                Coliziune[index]=rad->index;
            return ;
        }
        else
          if(rad->Sons[*p-'a']==0)rad->Sons[*p-'a']=new TRIE;
        AddInTrie(p+1,index,rad->Sons[*p-'a']);
    }
    inline void ParcugeTrie(){
        DfsTrie(root,0);
    }
};
 
class Solve : private Trie{
private:
    FILE *fin,*fout;
    int N,M;
    int SparseTable[2*NMAX][19];
    int Log2[2*NMAX];
    void BuildSparseTable(){
        for(int i=1;i<=DimEuler;++i)SparseTable[i][0]=Niv[Euleriana[i]];
        for(int j=1;(1<<j)<=DimEuler;++j)
            for(int i=1;i+(1<<j)-1<=DimEuler;++i)
                if(SparseTable[i][j-1]<SparseTable[i+(1<<(j-1))][j-1])SparseTable[i][j]=SparseTable[i][j-1];
                    else
                        SparseTable[i][j]=SparseTable[i+(1<<(j-1))][j-1];
        Log2[1]=0;
        for(int i=2;i<=DimEuler;++i)Log2[i]=Log2[i/2]+1;
    }
    int RMQ(int a,int b){
        int nrel=b-a+1;
        int put=Log2[nrel];
        int left=nrel-(1<<put);
        return min(SparseTable[a][put],SparseTable[a+left][put]);
    }
public:
    Solve(){
        fin=fopen("ratina.in","r");
        fout=fopen("ratina.out","w");
    }
    void ReadData(){
        fscanf(fin,"%d %d",&N,&M);
        fgetc(fin);
        for(int i=1;i<=N;++i){
            char Inter[NMAX_WORD]="";
            fgets(Inter,NMAX_WORD,fin);
            AddInTrie(Inter,i,root);
        }
    }
    void ReadQuery(){
        ParcugeTrie();
        BuildSparseTable();
        for(int i=1;i<=M;++i){
            int x,a,b;
            fscanf(fin,"%d %d",&x,&a);
            a=b=First[Coliziune[a]];
            for(int j=1,inter;j<x;++j){
                fscanf(fin,"%d",&inter);
                inter=First[Coliziune[inter]];
                a=min(a,inter);
                b=max(b,inter);
            }
             fprintf(fout,"%d\n",RMQ(a,b));
        }
    }
}T;
 
int main()
{
    T.ReadData();
    T.ReadQuery();
    return 0;
}