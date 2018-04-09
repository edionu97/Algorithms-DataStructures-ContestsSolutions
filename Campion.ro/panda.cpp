#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int n,m,t,a[501][501],p,l,c,k,s,fo[501][501],nre,mini=250001,v[250001],d[501][501];
bool ok(int x)
{int put=1<<s;
 return (x%put xor k%put)==put-1;
}
void citire()
{freopen("panda.in","r",stdin);
 freopen("panda.out","w",stdout);
 scanf("%d%d%d%d%d%d%d%d",&p,&n,&m,&t,&l,&c,&k,&s);
 for(int i=1;i<=t;i++)
 {int x,y;
  scanf("%d%d",&x,&y);
  fo[x][y]=1;
 }
 for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++)
  {scanf("%d",&a[i][j]);
   if(ok(a[i][j])){a[i][j]=1;nre++;}
   else a[i][j]=0;
  }
 if(a[l][c]==1){nre--;a[l][c]=0;}
}
struct elm
{int l,c;
}el;
queue<elm>q;
const short dx[]={-1,1,0,0};
const short dy[]={0,0,-1,1};
void rez(int lin,int col)
{el.l=lin;
 el.c=col;
 q.push(el);
 elm val,val1;
 while(!q.empty())
 {val=q.front();
  q.pop();
  for(int k=0;k<4;k++)
  {int xx=val.l+dx[k];
   int yy=val.c+dy[k];
   if(xx>0&&yy>0&&xx<=n&&yy<=m&&!d[xx][yy]&&a[xx][yy])
   {d[xx][yy]=d[val.l][val.c]+1;
    if(fo[xx][yy]&&d[xx][yy]<mini){mini=min(d[xx][yy],mini);v[mini]=1;}
    else if(fo[xx][yy]&&d[xx][yy]==mini)v[mini]++;

    val1.l=xx;
    val1.c=yy;
    q.push(val1);
   }
  }
 }
 printf("%d %d",mini,v[mini]);
}
int main()
{citire();
if(p==1)printf("%d",nre);
else rez(l,c);
    return 0;
}
