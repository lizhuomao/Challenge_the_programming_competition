#include <cstring>
#include <iostream>
using namespace std;

struct edge
{
    int from, to, cost;
};
const int MAX_E = 0x7fffffff, MAX_V = 0x7fffffff, INF = 0x7fffffff;
edge es[MAX_E];
int d[MAX_V], V, E;

void shortest_path(int s)
{
    for (int i = 0; i < V; i++) d[i] = INF;
    d[s] = 0;
    while (true)
    {
        bool update = false;
        for (int i = 0; i < E; i++)
        {
            edge e = es[i];
            if (d[e.from] != INF && d[e.to] > d[e.from] + e.cost)
            {
                d[e.to] = d[e.from] + e.cost;
                update = true;
            }
        }
        if (!update) break;
    }
}
//≈–∂œÀ¿∑Ò¥Ê‘⁄∏∫»¶
bool find_negative_loop()
{
    memset(d, 0, sizeof(d));
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < E; j++)
        {
            edge e = es[j];
            if (d[e.to] > d[e.from] + e.cost)
            {
                d[e.to] = d[e.from] + e.cost;
                if (i == V - 1) return false;
            }
        }
    }
    return true;
}

int main(void)
{
    return 0;
}