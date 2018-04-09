#include <iostream>
#include <cstring>
#include <cstdio>
#define Alfa_Size 27
using namespace std;
FILE *fin=fopen("trie.in","r");
FILE *fout=fopen("trie.out","w");
 
struct Trie
{
    int nrWord,nrFii;
    Trie *Litere[Alfa_Size];
    Trie()
    {
        nrFii=nrWord=0;
        memset(Litere,0,sizeof(Litere));
    }
};
 
Trie *Rad;
 
void Add_In_Trie(Trie *nod,char *s)
{
    if(*s=='\n'){
        ++nod->nrWord;
        return;
    }
    if(nod->Litere[*s-'a']==0){
        ++nod->nrFii;
        nod->Litere[*s-'a']=new Trie;
    }
    Add_In_Trie(nod->Litere[*s-'a'],s+1);
}
 
inline int GetPref(Trie *nod,char *s,int dim)
{
    if( *s=='\n' || nod->Litere[*s-'a']==0)return dim;
    return GetPref(nod->Litere[*s-'a'],s+1,dim+1);
}
 
inline int Nrcuv(Trie *nod,char *s)
{
    if(*s=='\n'){
        return nod->nrWord;
    }
    if(nod->Litere[*s-'a']==NULL)return 0;
    return Nrcuv(nod->Litere[*s-'a'],s+1);
}
 
inline bool DeleteWord(Trie *nod,char *s)
{
    if(*s=='\n')--nod->nrWord;
    else
        if(DeleteWord(nod->Litere[*s-'a'],s+1)){
            nod->Litere[*s-'a']=0;
            --nod->nrFii;
        }
    if(!nod->nrFii && !nod->nrWord && nod!=Rad){
        delete nod;
        return 1;
    }
    return 0;
}
 
inline void ReadData()
{
    Rad=new Trie;
    char x[21]="";
    fgets(x,21,fin);
    while(!feof(fin)){
        switch(x[0]){
            case '0':Add_In_Trie(Rad,x+2);break;
            case '1':DeleteWord(Rad,x+2);break;
            case '2':fprintf(fout,"%d\n",Nrcuv(Rad,x+2));break;
            case '3':fprintf(fout,"%d\n",GetPref(Rad,x+2,0));break;
        }
        fgets(x,21,fin);
    }
}
 
int main()
{
    ReadData();
    return 0;
}