#include <algorithm>
#include <iostream>
using namespace std;

const int MAX_Q = 100, INF = 0x7fffffff;
int P, Q, A[MAX_Q + 2], dp[MAX_Q + 1][MAX_Q + 2];

void solve()
{
    A[0] = 0;
    A[Q + 1] = P + 1;
    for (int q = 0; q <= Q; q++)
    {
        dp[q][q + 1] = 0;
    }
    for (int w = 2; w <= Q + 1; w++)
    {
        for (int i = 0; i + w <= Q + 1; i++)
        {
            int j = i + w, t = INF;  
            for (int k = i + 1; k < j; k++)
            {
                t = min(dp[i][k] + dp[k][j], t);
            }
            dp[i][j] = t + A[j] - A[i] - 2;
        }
    }
    cout << dp[0][Q + 1] << endl;
    return;
}

int main(void)
{
    cin >> P >> Q;
    for (int i = 0; i < Q; i++)
    {
        cin >> A[i];
    }
    solve();
    system("pause");
    return 0;
}