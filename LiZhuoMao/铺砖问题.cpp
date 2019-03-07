#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 15, M = 1000000000;
int n, m;
bool color[maxn][maxn];

int rec(int i, int j, bool used[maxn][maxn])
{
    if (j == m)
    {
        return rec(i + 1, 0, used);
    }
    if (i == n)
    {
        return 1;
    }
    if (used[i][j] || color[i][j])
    {
        return rec(i + 1, j, used);
    }
    int res = 0;
    used[i][j] = true;
    if (j + 1 < m && !used[i][j + 1] && !color[i][j + 1])
    {
        used[i][j + 1] = true;
        res += rec(i, j + 1, used);
        used[i][j + 1] = false;
    }
    if (i + 1 < n && !used[i + 1][j] && !color[i + 1][j])
    {
        used[i + 1][j] = true;
        res += rec(i, j + 1, used);
        used[i + 1][j] = false;
    }
    used[i][j] = false;
    return res % M;
}
void solve()
{
    bool used[maxn][maxn];
    memset(used, false, sizeof(used));
    cout << rec(0, 0, used) << endl;
    return;
}

int main(void)
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            color[i][j] = (c == 'x' ? true : false);
        }
    }
    solve();
    system("pause");
    return 0;
}