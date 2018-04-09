#include <iostream>
#include <utility>
#include <bitset>
#include <cstdio>
#include <queue>
#define NMAX 1001
using namespace std;
int n,m,h;
int Tabla[NMAX][NMAX];
void ReadData()
{FILE *fin=fopen("tsunami.in","r");
 fscanf(fin,"%d %d %d",&n,&m,&h);
 for(int i=1;i<=n;++i)
    for(int j=1;j<=m;++j)fscanf(fin,"%d",&Tabla[i][j]);
 fclose(fin);
}
const short dx[]={0,0,-1,1};
const short dy[]={-1,1,0,0};
queue< pair<int,int> >Q;
bitset<NMAX>Viz[NMAX];
bitset<NMAX>Pus[NMAX];
inline bool Cond(int x,int y)
{
    return x>=1&&x<=n&&y>=1&&y<=m;
}
void GetMatches(int x,int y)
{for(int k=0;k<4;++k)
    {int xx=x+dx[k];
        int yy=y+dy[k];
        if(Cond(xx,yy)&&Tabla[xx][yy]<h&&!Pus[xx][yy]&&Tabla[xx][yy])
            {Pus[xx][yy]=true;
             Q.push(make_pair(xx,yy));
            }
    }
}
queue< pair<int,int> >Fill;
void SimulateFill(int i,int j)
{
 Viz[i][j]=true;
 Fill.push(make_pair(i,j));
  while(!Fill.empty())
  {i=Fill.front().first;
    j=Fill.front().second;
    GetMatches(i,j);
        Fill.pop();
            for(int k=0;k<4;++k)
                {int x=i+dx[k];
                 int y=j+dy[k];
                    if(Cond(x,y)&&!Tabla[x][y]&&!Viz[x][y])
                        {Viz[x][y]=true;
                            Fill.push(make_pair(x,y));
                        }
                }
  }
 
}
int nr;
void GetStartPositions(int n,int m)
{
   for(int i=1;i<=n;++i)
    for(int j=1;j<=m;++j)
     if(!Tabla[i][j]&&!Viz[i][j])SimulateFill(i,j);
     while(!Q.empty())
            {++nr;
                Pus[Q.front().first][Q.front().second]=true;
                    GetMatches(Q.front().first,Q.front().second);
                Q.pop();
            }
 
}
void Write()
{
    FILE *fout=fopen("tsunami.out","w");
    fprintf(fout,"%d",nr);
    fclose(fout);
}
int main()
{ReadData();
 GetStartPositions(n,m);
 Write();
    return 0;
}