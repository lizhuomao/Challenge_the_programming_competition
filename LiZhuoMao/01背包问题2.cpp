#include <algorithm>
#include <iostream>
using namespace std;

const int MAX_N = 1005, MAX_V = 10005, INF = 0x7ffffff;
int dp[MAX_N + 1][MAX_V + 1], N, W, v[MAX_N + 1], w[MAX_N + 1];

void solve()
{
    fill(dp[0], dp[0] +  MAX_V + 1, INF);
    dp[0][0] = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= MAX_V; j++)
        {
            //cout << i << " " << j << " " << v[i] << " " << w[i]  << " " << dp[i][j] << " " << endl;
            if (j < v[i])
            {
                dp[i + 1][j] = dp[i][j];
            }
            else
            {
                dp[i + 1][j] = min(dp[i][j], dp[i][j - v[i]] + w[i]);
            }  
        }
    }
    int res = 0;
    for (int i = 0; i <= MAX_V; i++) 
    {
        //cout << dp[N][i] << endl;
        if (dp[N][i] <= W) { res = i;}
    }
    cout << res << endl;
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