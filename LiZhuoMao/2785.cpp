#include <algorithm>
#include <iostream>
using namespace std;

const int maxn = 4000 + 5;
int n, a[maxn], b[maxn], c[maxn], d[maxn], cd[maxn * maxn];

void solve()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cd[i * n + j] = c[i] + d[j];
        }
    }
    sort(cd, cd + n * n);
    long long res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int ab = -(a[i] + b[j]);
            res += upper_bound(cd, cd + n * n, ab) - lower_bound(cd, cd + n * n, ab);
        }
    }
    cout << res << endl;
    return;
}

int main(void)
{
    cin >> n;
    for (int i = 0; i < n; i++) 
    {
        cin >> a[i];
        cin >> b[i];
        cin >> c[i];
        cin >> d[i];
    }
    solve();
    system("pause");
    return 0;
}