#include <cmath>
#include <iostream>
using namespace std;

const int maxn = 10000 + 5, inf = 100000;
int n, k;
double l[maxn];

bool c(double x)
{
    int num = 0;
    for (int i = 0; i < n; i++)
    {
        num += (int)(l[i] / x);
    }
    return num >= k;
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
    printf("%.2f\n", floor(ub * 100) / 100);
    return;
}

int main(void)
{
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> l[i];
    solve();
    system("pause");
    return 0;
}