#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 15 + 1, inf = 0x7fffffff;
int n, d[maxn][maxn], dp[1 << maxn][maxn];

int rec(int s, int v)
{
    if (dp[s][v] > 0) return dp[s][v];
    if (v == 0 && (s == 1 << n) - 1) return dp[s][v] = 0;
    int res = inf;
    for (int u = 0; u < n; u++)
    {
        if (!(s >> u & 1))
        {
            res = min(res, rec((s | 1 << u), u) + d[v][u]);
        }
    }
    return dp[s][v] = res;
}
void solve()
{
    fill(dp[0], dp[0] + n * n, -1);
    cout << rec(0, 0) << endl;
    return;
}
void solve2()
{
    for (int s = 0; s < 1 << n; s++) fill(dp[s], dp[s] + n, inf);
    for (int s = (1 << n) - 2; s >= 0; s--)
    {
        for (v = 0; v < n; v++)
        {
            for (u = 0; u < n; u++)
            {
                if (!(s >> u & 1))
                {
                    dp[s][v] = min(dp[s][v], dp[s | 1 << u][u] + d[v][u]);
                }
            }
        }
    }
    return;
}

int main(void)
{
    return 0;
}