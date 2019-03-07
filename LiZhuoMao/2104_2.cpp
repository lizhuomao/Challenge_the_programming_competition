#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int st_size = (1 << 18) - 1, maxn = 100000;
int n, m, a[maxn], I[maxn], J[maxn], K[maxn], nums[maxn];
vector<int> dat[st_size];

void init(int k, int l , int r)
{
    if (r - l == 1) dat[k].push_back(a[l]);
    else 
    {
        int lch = k * 2  + 1, rch = k * 2 + 2;
        init(lch, l, (l + r) / 2);
        init(rch, (l + r) / 2, r);
        dat[k].resize(r - l);
        merge(dat[lch].begin(), dat[lch].end(), dat[rch].begin(), dat[rch].end(), dat[k].begin());
    }
    return;
}
int query(int i, int j, int x, int k, int l, int r)
{
    if (j <= l || r <= i) return 0;
    else if (i <= l && r <= j) return upper_bound(dat[k].begin(), dat[k].end(), x) - dat[k].begin();
    else
    {
        int lc = query(i, j, x, k * 2 + 1, l, (l + r) / 2);
        int rc = query(i, j, x, k * 2 + 2, (l + r) / 2, r);
        return lc + rc;
    }
}
void solve()
{
    for (int i = 0; i < n; i++) nums[i] = a[i];
    sort(nums, nums + n);
    init(0, 0, n);
    for (int i = 0; i < m; i++)
    {
        int l = I[i], r = J[i] + 1, k = K[i];
        int lb = -1, ub = n - 1;
        while (ub - lb > 1)
        {
            int md = (lb + ub) / 2;
            int c = query(l, r, nums[md], 0, 0, n);
            if (c >= k) ub = md;
            else lb = md;
        }
        cout << nums[ub] << endl;
    }
    return;
}

int main(void)
{
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++)
    {
        cin >> I[i] >> J[i] >> K[i];
    }
    solve();
    system("pause");
    return 0;
}