#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const int maxn = 10000;
const int dat_size = (1 << 18) - 1;
int n, a[maxn], l[maxn], r[maxn], x[maxn];
char t[maxn];
ll data[dat_size], datb[dat_size];

void add(int a, int b, int x, int l, int r)
{
    if (a <= l && r <= b) data[k] += x;
    else if (l < b && a < r)
    {
        datb[k] += (min(b, r) - max(a, l)) * x;
        add(a, b, x * 2 + 1, l, (l + r) / 2);
        add(a, b, x * 2 + 2, (l + r) / 2, r);
    }
    return;
}
ll sum(int a, int b, int k, int l, int r)
{
    if (b <= l || a >= r) return 0;
    else if (a <= l && r <= b) return data[k] * (r - l) + datb[k];
    else
    {
        ll res = (min(b, r) - max(a, l)) * data[k];
        res += sum(a, b, k * 2 + 1, l, (l + r) / 2);
        res += sum(a, b, k * 2 + 2, (l + r) / 2, r);
        return res;
    }
}
void solve()
{
    for (int i = 0; i < n; i++)
    {
        add(i, i + 1, a[i], 0, 0, n);
    }
    for (int i = 0; i < q; i++)
    {
        if (t[i] == 'C')
        {
            add(l[i], r[i] + 1, x[i], 0, 0, n);
        }
        else
        {
            cout << sum(l[i], r[i] + 1, 0, 0, n) << endl;
        }
        
    }
    return;
}

int main(void)
{
    
    return 0;
}