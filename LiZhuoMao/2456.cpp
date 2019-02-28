#include <algorithm>
#include <iostream>
using namespace std;

const int maxn = 100000, inf = 100000;
int n, m, x[maxn];

bool c(int d)
{
    int last = 0;
    for (int i = 1; i < m; i++)
    {
        int crt = last + 1;
        while (crt < n && x[crt] - x[last] < d) crt++;
        if (crt == n) return false;
        last = crt;
    }
    return true;
}
void solve()
{
    sort(x, x + n);
    int lb = 0, ub = inf;
    while (ub - lb > 1)
    {
        int mid = (lb + ub) / 2;
        if (c(mid)) lb = mid;
        else ub = mid;
    }
    cout << lb << endl;
    return;
}

int main(void)
{
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> x[i];
    solve();
    system("pause");
    return 0;
}