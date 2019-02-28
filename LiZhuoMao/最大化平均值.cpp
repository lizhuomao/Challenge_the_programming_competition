#include <algorithm>
#include <iostream>
using namespace std;

const int maxn = 10000, inf = 1000000;
int n, k, w[maxn], v[maxn];
double y[maxn];

bool c(double x)
{
    for (int i = 0; i < n; i++)
    {
        y[i] = v[i] - x * w[i];
    }
    sort(y, y + n);
    double sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += y[n - i - 1];
    }
    return sum >= 0;
}
void solve()
{
    double lb = 0, ub = inf;
    for (int i = 0; i < 100; i++)
    {
        double mid = (lb + ub) / 2;
        if (c(mid)) lb = mid;
        else ub = mid;
    }
    printf("%.2f", ub);
    return;
}

int main(void)
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> w[i] >> v[i];
    }
    solve();
    system("pause");
    return 0;
}