//Parcurgerea in latime grafuri neorientate

#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
using namespace std;
vector < int >G[101];
int n,m;

void ReadData()
{
    ifstream f("date.in");
    f>>n>>m;

    while(n--){
        int x,y;
        f>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    f.close();
}

queue < int >Q;
bool viz[101];

void BFS(int start)
{
    viz[start]=true;
    Q.push(start);
    while(!Q.empty()){
        start=Q.front();
        Q.pop();
        cout<<start<<' ';
        for( vector< int >::iterator it=G[start].begin();it!=G[start].end();++it)
            if(!viz[*it]){
                Q.push(*it);
                viz[*it]=true;
            }
    }
}

int main()
{
    int start;
    cout<<"DATI VARFUL DE PLECARE=";cin>>start;
    ReadData();
    BFS(start);
    return 0;
}
