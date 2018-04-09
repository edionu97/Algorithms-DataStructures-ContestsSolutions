#include <fstream>
#include <iostream>
#include <queue>
#include <utility>
using namespace std;
ifstream f("alee.in");
ofstream g("alee.out");
int a[176][176],n,m,pa,pb,sa,sb;
 
void citire()
{f>>n>>m;
 for(int i=1;i<=m;i++)
 {int x, y;
  f>>x>>y;
  a[x][y]=1;
 }
 f>>pa>>pb>>sa>>sb;
}
 
const int dx[]={0,0,-1,1};
const int dy[]={1,-1,0,0};
 
inline bool cor(int x,int y)
{if(x>=1&&x<=n&&y>=1&&y<=n)return 1;
 return 0;
}
 
queue < pair<int,int> >Q;
 
void solve(int x,int y){
    Q.push( make_pair (x,y) );
    a[x][y]=1;
    while(!Q.empty() && a[sa][sb]==0){
            for(int k=0;k<=3;k++){
                int ii,jj;
                ii=Q.front().first+dx[k];
                jj=Q.front().second+dy[k];
                if(a[ii][jj]==0&&cor(ii,jj)){
                    Q.push( make_pair(ii,jj));
                    a[ii][jj]=a[ii-dx[k]][jj-dy[k]]+1;
                }
            }
        Q.pop();
    }
 g<<a[sa][sb];
}
int main()
{citire();
 solve(pa,pb);
 
   return 0;
}
© 2004-2018 Asociatia infoarena