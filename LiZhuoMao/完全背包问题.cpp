#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

const int MAX_N = 100 + 5, MAX_M = 10000 + 5;
int dp[MAX_N][MAX_M], w[MAX_N], v[MAX_N], N, W;

void solve()
{
   // memset(dp, 0, sizeof(dp));
   for (int i = 0; i <= W; i++)
   {
       dp[0][i] = 0;
   }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            for (int k = 0; k * w[i] <= j; k++)
            {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - k * w[i]] + v[i] * k);
            }
        }
    }
    cout << dp[N][W] << endl;
}

int main(void)
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> w[i] >> v[i];
    }
    cin >> W;
    solve();
    system("pause");
    return 0;
}