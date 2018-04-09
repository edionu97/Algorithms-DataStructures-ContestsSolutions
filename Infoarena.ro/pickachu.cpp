#include <cstdio>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;
 
#define MAXN 100100
#define MAXARB (1 << 18)
#define pb push_back
#define mp make_pair
#define PII pair<int, int>
#define left (nod<<1)
#define right ((nod<<1) | 1)
#define mid ((st+dr) >> 1)
#define llong long long
 
int N, K, sir[MAXN], arb[MAXARB], med[MAXN];
vector<int> A;
llong res;
llong arb2[MAXARB];
 
int getindex(int x) {
    return (int)(lower_bound(A.begin(), A.end(), x)-A.begin());
}
 
int query(int nod, int st, int dr, int k)
{
    if(st == dr)
        return st;
    if(arb[left] >= k) return query(left, st, mid, k);
    return query(right, mid+1, dr, k-arb[left]);
}
 
void update(int nod, int st, int dr, int k, int sgn)
{
    arb[nod]+=sgn;
    if(st == dr)
        return ;
    if(k <= mid) update(left, st, mid, k, sgn);
    else update(right, mid+1, dr, k, sgn);
}
 
void update2(int nod, int st, int dr, int k, int sgn)
{
    arb[nod]+=sgn;
    arb2[nod] += (llong)sgn*A[k];
    if(st == dr) return ;
    if(k <= mid) update2(left, st, mid, k, sgn);
    else update2(right, mid+1, dr, k, sgn);
}
 
llong sum(int nod, int st, int dr, int k)
{
    if(st == dr) return arb2[nod];
    if(arb[left] >= k) return sum(left, st, mid, k);
    return arb2[left]+sum(right, mid+1, dr, k-arb[left]);
}
 
void solve(void)
{
    int i, j, k, s, lamisto;
    llong aux, aux2;
    sort(A.begin(), A.end());
    for(i = 0; i < K; i++)
        update(1, 0, N-1, getindex(sir[i]), +1);
    if(K%2 == 1) s = 1;
    else s = 0;
    med[0] = A[query(1, 0, N-1, K/2+s)];
    for(i = 1; i+K-1 < N; i++)
    {
        int ttt = getindex(sir[i-1]);
        int qqq = getindex(sir[i+K-1]);
        update(1, 0, N-1, getindex(sir[i-1]), -1);
        update(1, 0, N-1, getindex(sir[i+K-1]), +1);
        med[i] = A[query(1, 0, N-1, K/2+s)];
    }
    for(i = 0; i < MAXARB; i++) arb[i] = 0;
    for(i = 0; i < K; i++)
        update2(1, 0, N-1, getindex(sir[i]), +1);
    if(K%2 == 0) lamisto = 1;
    else lamisto = 0;
    aux = sum(1, 0, N-1, K/2-lamisto), aux2 = sum(1, 0, N-1, K)-med[0];
    res = (llong)med[0]*(K/2-lamisto)-aux;
    res += (llong)(aux2-aux)-med[0]*(llong)(K/2);
    for(i = 1; i+K-1 < N; i++)
    {
        update2(1, 0, N-1, getindex(sir[i-1]), -1);
        update2(1, 0, N-1, getindex(sir[i+K-1]), +1);
        aux = sum(1, 0, N-1, K/2-lamisto), aux2 = sum(1, 0, N-1, K)-med[i];
        llong q;
        q = (llong)med[i]*(K/2-lamisto)-aux; q += (llong)(aux2-aux)-med[i]*(llong)(K/2);
        res = min(res, q);
    }
}
 
int main(void)
{   
    freopen("pikachu.in", "rt", stdin);
    freopen("pikachu.out", "wt", stdout);
 
    int i;
    scanf("%d %d", &N, &K);
 
    for(i = 0; i < N; i++)
        scanf("%d", &sir[i]), A.pb(sir[i]);
 
    solve();
 
    printf("%lld\n", res);
 
    return 0;
}