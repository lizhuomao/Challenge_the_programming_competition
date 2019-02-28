#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

const int maxn = 500 + 5, dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};
int h, w, n, x1[maxn], x2[maxn], y1[maxn], y2[maxn];
bool fld[maxn * 6][maxn * 6];

int compress(int *x1, int *x2, int wide)
{
    vector<int> xs;
    for (int i = 0; i < n; i++)
    {
        for (int d = -1; d <= 1; d++)
        {
            int tx1 = x1[i] + d, tx2 = x2[i] + d;
            if (1 <= tx1 && tx1 <= wide) xs.push_back(tx1);
            if (1 <= tx2 && tx2 <= wide) xs.push_back(tx2);
        }
    }
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    for (int i = 0; i < n; i++)
    {
        x1[i] = find(xs.begin(), xs.end(), x1[i]) - xs.begin();
        x2[i] = find(xs.begin(), xs.end(), x2[i]) - xs.begin();
    }
    return xs.size();
}

void solve()
{
    w = compress(x1, x2, w);
    h = compress(y1, y2, h);
    memset(fld, 0, sizeof(fld));
    for (int i = 0; i < n; i++)
    {
        for (int y = y1[i]; y <= y2[i]; y++)
        {
            for (int x = x1[i]; x <= x2[i]; x++)
            {
                fld[y][x] = true;
            }
        }
    }
    int ans = 0;
    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            if (fld[y][x]) continue;
            ans++;
            queue<pair<int, int>> que;
            que.push(make_pair(x, y));
            while (!que.empty())
            {
                int sx = que.front().first;
                int sy = que.front().second;
                que.pop();
                for (int i = 0; i < 4; i++)
                {
                    int tx = sx + dx[i];
                    int ty = sy + dy[i];
                    if (tx < 0 || w <= tx || ty < 0 || h <= ty) continue;
                    if (fld[ty][tx]) continue;
                    que.push(make_pair(tx, ty));
                    fld[ty][tx] = true;
                }
            }
        }
    }
    cout << ans << endl;
    return;
}

int main(void)
{
    cin >> w >> h >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x1[i];
        cin >> x2[i];
        cin >> y1[i];
        cin >> y2[i];
    }
    solve();
    system("pause");
    return 0;
}