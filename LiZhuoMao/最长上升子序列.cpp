#include <algorithm>
#include <iostream>
using namespace std;

const int MAX_N = 1000 + 5, INF = 0x7fffffff;
int N, dp[MAX_N], a[MAX_N];

void solve()
{
    int res = 0;
    for (int i = 0; i < N; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        res = max(res, dp[i]);
    }
    cout << res << endl;
    return;
}

void solve2()
{
    fill(dp, dp + MAX_N, INF);
    for (int i = 0; i < N; i++)
    {
        *lower_bound(dp, dp + N, a[i]) = a[i];
    }
    cout << lower_bound(dp, dp + N, INF) - dp << endl;
    return;
}

int main(void)
{
    cin >> N;
    for (int i = 0; i < N; i++)    
    {
        cin >> a[i];
    }
    solve2();
    system("pause");
    return 0;
}