const int MAX_N = 0x7ffffffe, MAX_M = 0x7ffffffe;
int n, m;
int a[MAX_N];
int dp[MAX_N + 1][MAX_M + 1];

void solve()
{
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (j - 1 - a[i] >=0)
            {
                dp[i + 1][j] = (dp[i + 1][j - 1] + dp[i][j] - dp[i][j - 1 - a[i]] + M) % M;
            }
            else
            {
                dp[i + 1][j] = (dp[i + 1][j - 1] + dp[i][j]) % M;
            }
        }
    }
    printf("%d\n", dp[n][m]);
}