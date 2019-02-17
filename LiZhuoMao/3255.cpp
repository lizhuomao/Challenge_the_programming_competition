#include <functional>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

const int MAX_N = 5000 + 5, INF = 0x7fffffff;
struct edge
{
    int to, cost;
};
vector<edge> G[MAX_N];
int N, R, dist[MAX_N], dist2[MAX_N];
typedef pair<int, int> P;

void solve()
{
    priority_queue<P, vector<P>, greater<P> > que;
    fill(dist, dist + N, INF);
    fill(dist2, dist2 + N, INF);
    dist[0] = 0;
    que.push(P(0, 0));
    while (!que.empty())
    {
        P p = que.top();
        que.pop();
        int v = p.second, d = p.first;
        //cout << v << " " << d << " " << dist2[v] << " " << G[v].size() << endl;
        if (d > dist2[v]) continue;
        for (int i = 0; i < G[v].size(); i++)
        {
            edge &e = G[v][i];
           //cout << e.to << " " << e.cost << dist[e.to] << " " << dist2[e.to] << endl;
            int d2 = e.cost + d;
            if (d2 < dist[e.to])
            {
                swap(d2, dist[e.to]);
                que.push(P(dist[e.to], e.to));
            }
            if (d2 < dist2[e.to] && d2 > dist[e.to])
            {
                dist2[e.to] = d2;
                que.push(P(d2, e.to));
            }
        }
    }
    printf("%d\n", dist2[N - 1]);
    return;
}

int main(void)
{
    cin >> N >> R;
    for (int i = 0; i < R; i++)   
    {
        int a, b, cost;
        cin >> a >> b >> cost;
        a--;
        b--;
        G[a].push_back(edge{b, cost});
        G[b].push_back(edge{a, cost});
    }
    solve();
    system("pause");
    return 0;
}