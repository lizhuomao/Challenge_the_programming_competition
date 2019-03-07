#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 100000 + 5, b = 1000;
int n, m, a[maxn], i[maxn], j[maxn], k[maxn], nums[maxn];
vector<int> bocket[maxn / b];

void solve()
{
    for (int i = 0; i < n; i++)
    {
        bocket[i / b].push_back(a[i]);
        nums[i] = a[i];
    }
    sort(nums, nums + n);
    for (int p = 0; p < n / b; p++) sort(bocket[p].begin(), bocket[p].end());
    for (int p = 0; p < m; p++)
    {
        int l = i[p], r = j[p], values = k[p];
        int lb = -1, ub = n - 1;
        while (ub - lb > 1)
        {
            int md = (lb + ub) / 2;
            int x = nums[md];
            int tl = l, tr = r, c = 0;
            while (tl < tr && tl % b != 0) if (a[tl++] <= x) c++;
            while (tl < tr && tr % b != 0) if (a[--tr] <= x) c++;
            while (tl < tr)
            {
                int tempb = tl / b;
                c += upper_bound(bocket[tempb].begin(), bocket[tempb].end(), x) - bocket[tempb].begin();
                tl += b;
            }
            if (c >= values) ub = md;
            else lb = md;
        }
            cout << nums[ub];
    }
    return;
}

int main(void)
{
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int p = 0; p < m; p++)
    {
        cin >> i[p] >> j[p] >> k[p];
    }
    solve();
    system("pause");
    return 0;
}