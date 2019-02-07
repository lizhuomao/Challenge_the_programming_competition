#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;

const int MAX_N = 100 + 5;
int N, W;
int w[MAX_N], v[MAX_N], dp[MAX_N][MAX_N];

int rec(int i, int j)
{
    if (dp[i][j] >= 0)
    {
        return dp[i][j];
    }
    int res;
    if (i == N) 
    {
        res = 0;
    }
    else if (j < w[i])
    {
        res = rec(i + 1, j);
    }
    else
    {
        res = max(rec(i + 1, j), rec(i + 1, j - w[i]) + v[i]);
    }
    return dp[i][j] = res;
}

void solve_1()
{
    memset(dp, -1, sizeof(dp));
    printf("%d\n", rec(0, W));
}

void solve_2()
{
    for (int i = 0; i <= W; i++)
    {
        dp[N][i] = 0;
    }
    for (int i = N - 1; i >= 0; i--)
    {
        for (int j = 0; j <= W; j++)
        {
            if (j < w[i])
            {
                dp[i][j] = dp[i + 1][j];
            }
            else
            {
                dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - w[i]] + v[i]);
            }  
        }
    }
    printf("%d\n", dp[0][W]);
}

int main(void)
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> w[i] >> v[i];
    }
    cin >> W;
    solve_2();
    system("pause");
    return 0;
}
