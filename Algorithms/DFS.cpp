//Parcurgerea in adancime

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream f("date.in");
vector <int>G[101];
int n,m;

void ReadData()
{
    ifstream f("date.in");
    f>>n>>m;
    while(m--){
        int x,y;
        f>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    f.close();
}

bool Fol[101];

inline bool Cresc(int a,int b)
{
    return a<b;
}

inline void Sortare()
{
    for(int i=1;i<=n;++i)
        sort(G[i].begin(),G[i].end(),Cresc);
}

inline void DFS(int start)
{
    Fol[start]=true;
    vector<int>::iterator it;
    cout<<start<<' ';
    for(it=G[start].begin();it!=G[start].end();++it)
        if(!Fol[*it])DFS(*it);

}

int start;

int main()
{
    ReadData();
    cout<<"DATI VARFUL DE PLECARE=";cin>>start;
    Sortare();
    DFS(start);
    return 0;
}
