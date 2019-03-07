#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 15, M = 1000000000;
int n, m, dp[2][1 << maxn];
bool color[maxn][maxn];

void solve()
{
    int *crt = dp[0], *next = dp[1];
    crt[0]  = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            for (int used = 0; used < 1 << m; used++)
            {
                if ((used >> j & 1) || color[i][j])
                {
                    next[used] = crt[used & ~(1 << j)];
                }
                else
                {
                    int res = 0;
                    if (j + 1 < m && !(used >> (j + 1) & 1) && !color[i][j + 1])
                    {
                        res += crt[used | 1 << (j + 1)];
                    }
                    if (i + 1 < n && !color[i + 1][j])
                    {
                        res += crt[used | 1 << j];
                    }
                    next[used] = res % M;
                }
            }
            swap(next, crt);
        }
    }
    cout << crt[0] << endl;
    return;
}

int main(void)
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            color[i][j] = (c == 'x' ? true : false);
        }
    }
    solve();
    system("pause");
    return 0;
}