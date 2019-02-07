#include <iostream>
using namespace std;

const int MAX_N = 1000, MAX_M = 1000;
int n, m, M, dp[MAX_M + 1][MAX_N + 1];

void solve()
{
    dp[0][0] = 1;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (j - i >= 0)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - i] % M;
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[m][n] << endl;
    return;
}

int main(void)
{
    cin >> n >> m;
    cin >> M;
    solve();
    system("pause");
    return 0;
}