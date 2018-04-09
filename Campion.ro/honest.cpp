#include <iostream>
#include <cmath>
#include <deque>
#include <cstdio>
using namespace std;
struct much
{int b[1002],nre;
}a[1002];
int n,m,nrc;
void citire()
{freopen("honest.in","r",stdin);
 freopen("honest.out","w",stdout);
 scanf("%d%d",&n,&m);
 int x,y;
 char ch;
 for(int i=1;i<=m;i++)
 {scanf("%d %c %d",&x,&ch,&y);
  int ok=1;
  if(ch=='m')ok=-1;
  a[x].b[++a[x].nre]=ok*y;
 }
}
double modul(double x)
{return abs(x);}
bool pus[1002];
deque<int>sol;
void rezolv(int i,int j,int fst)
{int val=modul(a[i].b[j]);
 if(j<a[i].nre&&!pus[val])rezolv(i,j+1,fst);
 else
  if(pus[val]&&j<a[i].nre)
  {int c=modul(a[i].b[j]);
    while(pus[c]&&j<=a[i].nre){j++;c=modul(a[i].b[j]);}
   if(j<=a[i].nre)rezolv(i,j,fst);
  }
 if(a[val].nre&&!pus[val])rezolv(val,1,i);
 if(!pus[val]&&val)
 {pus[val]=1;
  sol.push_front(val);
 }
}
int rez[1001];

void svm(int x)
{for(int i=1;i<=a[x].nre;i++)
 {int c=modul(a[x].b[i]);
  if(rez[c]==-1)
  if(a[x].b[i]>0)rez[c]=0;
  else {rez[c]=1;nrc++;}
 }
}

void svc(int x)
{for(int i=1;i<=a[x].nre;i++)
 {int c=modul(a[x].b[i]);
  if(rez[c]==-1)
    if(a[x].b[i]>0){rez[c]=1;nrc++;}
   else rez[c]=0;
 }
}

void svn(int x)
{for(int i=1;i<=a[x].nre;i++)
 {int c=modul(a[x].b[i]);
  if(a[x].b[i]>0&&rez[c]==0)
  {rez[x]=0;
   break;
  }
 if(a[x].b[i]<0&&rez[c]==1)
  {rez[x]=0;
   break;
  }
 }
 if(rez[x]==-1){rez[x]=1;nrc++;}
 if(rez[x]==1){svc(x);nrc++;}
 if(rez[x]==0)svc(x);
}
void calc(int x)
{if(!rez[x])svm(x);
 else
  if(rez[x])svc(x);
 else svn(x);
}
void calculare_c(int n)
{int val=sol.front();
 for(int i=1;i<=n;i++)rez[i]=-1;
 rez[val]=1;
 nrc++;
 for(int i=1;i<=a[val].nre;i++)
  {int c=modul(a[val].b[i]);
   if(a[val].b[i]>0){rez[c]=1;nrc++;}
   else rez[c]=0;
  }
 sol.pop_front();
 while(!sol.empty())
 {val=sol.front();
  calc(val);
  sol.pop_front();
 }
}
void afis(int n)
{int nre=0;
 if(nrc>=n/2)for(int i=1;i<=n;i++)printf("%d\n",rez[i]);
 else
  for(int i=1;i<=n;i++)printf("%d\n",!rez[i]);
}
int main()
{citire();
for(int i=1;i<=n;i++)
 if(!pus[i]){rezolv(i,1,i);pus[i]=1;sol.push_front(i);}
calculare_c(n);
 afis(n);
return 0;
}
