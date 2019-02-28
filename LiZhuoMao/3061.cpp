#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 100000;
int n, s, sum[maxn + 1], a[maxn];

void solve()
{
    sum[0] = 0;
    for (int i = 0; i < n; i++)
    {
        sum[i + 1] = sum[i] + a[i];
    }
    if (sum[n] < s)
    {
        cout << 0 << endl;
        return;
    }
    int res = n;
    for (int ss = 0; sum[ss] + s <= sum[n]; ss++)
    {
        int t = lower_bound(sum + ss, sum + n, sum[ss] + s) - sum;
        res = min(res, t - ss);
    }
    cout << res << endl;
    return;
}

int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> s;
        for (int i = 0; i < n; i++) cin >> a[i];
        solve();
    }
    system("pause");
    return 0;
}