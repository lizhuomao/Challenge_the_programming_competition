#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_R = 500000 + 5;
int E, V, N, M, R, x[MAX_R], y[MAX_R], d[MAX_R], par[MAX_R], Rank[MAX_R];
struct edge
{
    int from, to, cost;
};
edge es[MAX_R];

bool cmp(const edge &a, const edge &b)
{
    return a.cost < b.cost;
}
void init(int K)
{
    for (int i = 0; i <= K; i++) 
    {
        par[i] = i;
        Rank[i] = 0;
    }
}
int find(int x)
{
    if (x == par[x]) return x;
    else return par[x] = find(par[x]);
}
void unite(int x, int y)
{
    int a = find(x);
    int b = find(y);
    if (a == b) return;
    if (Rank[a] > Rank[b])
    {
        Rank[b] = Rank[a];
        par[b] = a;
    }
    else
    {
        if (Rank[a] == Rank[b]) {
             Rank[a]++;
        }
        else
        {
            Rank[a] = Rank[b];
        }
        par[a] = b;
    }
    
}
bool same(int x, int y)
{
    return find(x) == find(y);
}
int kruskal()
{
    int res = 0;
    sort(es, es + E, cmp);
    init(V);
    for (int i = 0; i < E; i++)
    {
        edge e = es[i];
        if (!same(e.to, e.from))
        {
            unite(e.to, e.from);
            res += e.cost;
        }
    }
    return res;
}
void solve()
{
    V = N + M;
    E = R;
    for (int i = 0; i < R; i++)
    {
        es[i] = edge{x[i], y[i] + N, -d[i]};
    }
    cout << 10000LL * (N + M) + kruskal() << endl;
    return;
}

int main(void)
{
    int cnt;
    cin >> cnt;
    while (cnt--)
    {
   //     cin >> N >> M >> R;
        scanf("%d %d %d", &N, &M, &R);
        for(int i = 0; i < R; i++)
        {
            //cin >> x[i] >> y[i] >> d[i];
            scanf("%d %d %d", &x[i], &y[i], &d[i]);
        }
        solve();
    }
    system("pause");
    return 0;
}