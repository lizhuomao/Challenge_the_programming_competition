#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;

const int MAX_N = 1000 + 5;
char s[MAX_N], t[MAX_N];
int dp[MAX_N][MAX_N], N, M;

void solve()
{
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (s[i] == t[j])
            {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            }
            else
            {
                dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }
    cout << dp[N][M] << endl;
    return;
}

int main(void)
{
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> s[i];
    for (int i = 0; i < M; i++) cin >> t[i];
    solve();
    system("pause");
    return 0;
}