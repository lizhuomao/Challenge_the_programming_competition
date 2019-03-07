#include <iostream>
using namespace std;

const int maxn = 10000;
typedef long long ll;
int n, q, l[maxn], r[maxn], x[maxn];
char t[maxn];
ll bit0[maxn + 1], bit1[maxn + 1];

ll sum(ll *b, int i)
{
    ll s = 0;
    while (i > 0)
    {
        s += b[i];
        i = i - (i & -i);
    }
    return s;
}

void add(ll *b, int i, int v)
{
    while (i <= n)
    {
        b[i] += v;
        i = i + (i & -i);
    }
    return;
}
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        add(bit0, i, a[i]);
    }
    for (int i = 0; i < q; i++)
    {
        if (t[i] == 'C')
        {
            add(bit0, l[i], -x[i] * (l[i] - 1));
            add(bit1, l[i], x[i]);
            add(bit0, r[i] + 1, x[i] * r[i]);
            add(bit1, r[i] + 1, -x[i]);
        }
        else
        {
            ll res = 0;
            res += sum(bit0, r[i]) + sum(bit1, r[i]) * r[i];
            res -= sum(bit0, l[i] - 1) + sum(bit1, l[i] - 1) * (l[i] - 1);
            cout << res << endl;
        }
    }
    return;
}

int main(void)
{
    solve();
    return 0;
}
