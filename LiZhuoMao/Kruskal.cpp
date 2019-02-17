#include <algorithm>
#include <iostream>
using namespace std;

struct edge
{
    int u, v, cost;
};
const int MAX_E = 0x7fffffff;
edge es[MAX_E];
int V, E, par[MAX_E];

bool cmp(const edge &a, const edge &b)
{
    return a.cost < b.cost;
}
void init(int N)
{
    for(int i = 0; i < N; i++)
    {
        par[i] = i;
    }
}
int find(int x)
{
    if (par[x] == x) return x;
    else return par[x] = find(par[x]);
}
void unite(int x, int y)
{
    int a = find(x);
    int b = find(y);
    par[a] = b;
    return;
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
        if (!same(e.u, e.v))
        {
            unite(e.u, e.v);
            res += e.cost;
        }
    }
    return res;
}

int main(void)
{
    return 0;
}