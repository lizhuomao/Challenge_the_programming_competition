#include <algorithm>
#include <iostream>
using namespace std;

const int MAX_V = 0x7fffffff;
int d[MAX_V][MAX_V], V;

void warshall_floyd()
{
    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

const int INF = 0x7fffffff;
int cost[MAX_V][MAX_V], mincost[MAX_V];
bool used[MAX_V];

int prim()
{
    for (int i = 0; i < V; i++)
    {
        mincost[i] = INF;
        used[i] = false;
    }
    mincost[0] = 0;
    int res = 0;
    while (true)
    {
        int v = -1;
        for (int u = 0; u < V; u++) if (!used[u] && (v == -1 || mincost[u] < mincost[v])) v = u;
        if (v == -1) break;
        used[v] = true;
        res += mincost[v];
        for (int u = 0; u < V; u++)
        {
            mincost[u] = min(mincost[u], cost[v][u]);
        }
    }
    return res;
}

int main(void)
{
    return 0;
}