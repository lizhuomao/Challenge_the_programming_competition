#include <iostream>
using namespace std;

const int maxn = 1000000;
int n, k, a[maxn];

void solve()
{
    int lb = -1, ub = n;
    while (ub - lb > 1)
    {
        int mid = (ub + lb) / 2;
        if (a[mid] >= k)
        {
            ub = mid;
        }
        else
        {
            lb = mid;
        }
    }
    cout << ub;
    return;
}

int main(void)
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> k;
    solve();
    system("pause");
    return 0;
}