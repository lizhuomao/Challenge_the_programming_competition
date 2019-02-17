#include <queue>
#include <functional>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

//邻接矩阵
const int MAX_V = 0x7fffffff, INF = 0x7fffffff;
int cost[MAX_V][MAX_V], d[MAX_V], V;
bool used[MAX_V];

void dijkstra(int s)
{
    fill(d, d + V, INF);
    fill(used, used + V, false);
    d[s] = 0;
    while (true)
    {
        int v = -1;
        for (int u = 0; u < V; u++)
        {
            if (!used[u] && (d[u] < d[v] || v == -1)) v = u;
        }
        if (v == -1) break;
        used[v] = true;
        for (int u = 0; u < V; u++)
        {
            d[u] = min(d[u], d[v] + cost[v][u]);
        }
    }
    return;
}

//优先队列
struct edge
{
    int to, cost;
};
typedef pair<int, int> P;
int V, d[MAX_V];
vector<edge> G[MAX_V];

void dijkstra(int s)
{
    priority_queue<P, vector<P>, greater<P>> que;
    fill(d, d + V, INF);
    d[s] = 0;
    que.push(P{0, s});
    while (!que.empty())
    {
        P p = que.top();
        que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        for (int i = 0; i < G[v].size(); i++)
        {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost)
            {
                d[e.to] = d[v] + e.cost;
                que.push(P{d[e.to], e.to});
            }
        }
    }
    return;
}

int main(void)
{
    return 0;
}