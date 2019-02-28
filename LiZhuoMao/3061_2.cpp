#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 100000;
int n, s, sum[maxn + 1], a[maxn];

void solve()
{
    int res = n + 1;
    int ss = 0, t = 0, sum = 0;
    for (;;)
    {
        while (t < n && sum < s)
        {
            sum += a[t++];
        }
        if (sum < s) break;
        res = min(res, t - ss);
        sum -= a[s++];
    }
    if (res > n)
    {
        res = 0;
    }
    cout << res << endl;
    return;
}

int main(void)
{
    cin >> n >> s;
    for (int i = 0; i < n; i++) cin >> a[i];
    solve();
    system("pause");
    return 0;
}