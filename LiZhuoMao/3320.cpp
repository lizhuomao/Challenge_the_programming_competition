#include <map>
#include <set>
#include <iostream>
using namespace std;

const int maxn = 1000000 + 5;
int p, a[maxn];

void solve()
{
    set<int> all;
    for (int i = 0; i < p; i++)
    {
        all.insert(a[i]);
    }
    int n = all.size();
    int s = 0, t = 0, num = 0;
    map<int, int> count;
    int res = p;
    for (;;)
    {
        while (t < p && num < n)
        {
            if (count[a[t++]]++ == 0) num++;
        }
        if (num < n) break;
        res = min(res, t - s);
        if (--count[a[s++]] == 0)
        {
            num--;
        }
    }
    cout << res << endl;
    return;
}

int main(void)
{
    cin >> p;
    for (int i = 0; i < p; i++) cin >> a[i];
    solve();
    system("pause");
    return 0;
}