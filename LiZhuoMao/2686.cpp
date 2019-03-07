#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 8, maxm = 30, inf = 0x7fffffff;
int n, m, a, p, b, t[maxn], d[maxm][maxm];
double dp[1 << maxn][maxm];

void solve()
{
    for (int i = 0; i < 1 << n; i++) fill(dp[i], dp[i] + m, inf);
    dp[(1 << n) - 1][a - 1] = 0;
    double res = inf;
    for (int s = (1 << n) - 1; s >= 0; s--)
    {
        res = min(res, dp[s][b - 1]);
        for (int v = 0; v < m; v++)
        {
            for (int i = 0; i < n; i++)
            {
                if (s >> i & 1)
                {
                    for (int u = 0; u < m; u++)
                    {
                        if (d[v][u] >= 0)
                        {
                            dp[s & ~(1 << i)][u] = min(dp[s & ~(1 << i)][u], dp[s][v] + ((double)d[v][u] / t[i]));
                        }
                    }
                }
            }
        }
    }
    if (res == inf) cout << "Impossible" << endl;
    else printf("%.3f\n", res);
    return;
}

int main(void)
{
    cin >> n >> m >> p >> a >> b;
    for (int i = 0; i < n; i++) cin >> t[i];
    for (int i = 0; i < m; i++) fill(d[i], d[i] + m, -1);
    for (int i = 0; i < p; i++)
    {
        int e1, e2, cost;
        cin >> e1 >> e2 >> cost;
        d[e1][e2] = d[e2][e1] = cost;
    }
    solve();
    system("pause");
    return 0;
}