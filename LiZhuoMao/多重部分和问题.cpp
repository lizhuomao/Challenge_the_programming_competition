#include <iostream>
using namespace std;

const int MAX_N = 100, MAX_K = 100000;
bool dp[MAX_N + 1][MAX_K + 1];
int a[MAX_N], m[MAX_N], N, K;

void solve()
{
    dp[0][0] = true;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= K; j++)
        {
            for (int k = 0; k <= m[i] && a[i] * k <= j; k++)
            {
                dp[i + 1][j] |= dp[i][j - a[i] * k];
            }
        }
    }
    if (dp[N][K]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return;
}

int main(void)
{
    cin >> N;
    for (int i = 0; i < N; i++) cin >> a[i];
    for (int i = 0; i < N; i++) cin >> m[i];
    cin >> K;
    solve();
    system("pause");
    return 0;
}