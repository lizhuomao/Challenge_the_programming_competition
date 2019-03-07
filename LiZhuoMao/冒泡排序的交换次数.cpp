#include <iostream>
using namespace std;

const int maxn = 100000 + 5;
int n, a[maxn], bit[maxn + 1];
typedef long long ll;

void buildbit()
{
    for (int i = 0; i < n; i++)
    {
        bit[i + 1] = a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        int j = i + (i & - i);
        if (j <= n)
        {
            bit[j] += bit[i];
        }
    }
    return;
}
int sum(int i)
{
    int s = 0;
    while (i > 0)
    {
        s += bit[i];
        i = i - (i & -i);
    }
    return s;
}
void add(int i, int x)
{
    while (i <= n)
    {
        bit[i] += x;
        i = i + (i & -i);
    }
    return;
}
void solve()
{
    //buildbit();
    ll ans = 0LL;
    for (int i = 0; i < n; i++)
    {
        int temp = sum(a[i]);
        ans += i - temp;
        cout << "i = " << i << " ans = " << ans << " temp = " << temp << endl;
        add(a[i], 1);
        for (int i = 1 ; i <= n; i++) cout << bit[i] << " ";
        cout << endl;
    }
    cout << ans << endl;
    return;
}

int main(void)
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    solve();
    system("pause");
    return 0;
}