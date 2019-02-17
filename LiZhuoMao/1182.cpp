#include <iostream>
using namespace std;
// 100 7
// 1 101 1
// 2 1 2
// 2 2 3
// 2 3 3
// 1 1 3
// 2 3 1
// 1 5 5
const int MAX_K = 100000 + 5, MAX_N = 50000 + 5;
int N, K, T[MAX_K], X[MAX_K], Y[MAX_K], par[MAX_N * 3];

void init(int n)
{
    for (int i = 0; i <= n; i++)
    {
        par[i] = i;
    }
    return;
}
int find(int x)
{
    if (par[x] == x) return x;
    else return par[x] = find(par[x]);
}
void unite(int x, int y)
{
    int a = find(x);
    int b = find(y);
    //cout << "u" << " " << a << " " << b << " " << x << " " << y << endl;
    par[a] = b;
}
bool same(int x, int y)
{
    //cout << "s " << find(x) <<" " << find(y) << endl;
    return find(x) == find(y);
}
void solve()
{
    init(N * 3);
    int ans = 0;
    for (int i = 0; i < K; i++)
    {
        int t = T[i];
        int x = X[i] - 1;
        int y = Y[i] - 1;
        if (x < 0 || x >= N || y < 0 || y >= N)
        {
            ans++;
      //      cout << t << " " << x << " " << y << endl;
            continue;
        }
        if (t == 1)
        {
            if (same(x, y + N) || same(x, y + 2 * N))
            {
                ans++;
        //        cout << t << " " << x << " " << y << endl;
                continue;
            }
            else
            {
                unite(x, y);
                unite(x + N, y + N);
                unite(x + N * 2, y + N * 2);
            }
        }
        else
        {
            if (same(x, y) || same(x, y + N * 2))
            {
                ans++;
          //      cout << t << " " << x << " " << y << endl;
                continue;
            }
            else
            {
                unite(x, y + N);
                unite(x + N, y + N * 2);
                unite(x + N * 2, y);
            }
        }
        //cout << ans << endl;
    }
    cout << ans << endl;
    return;
}

int main(void)
{
    cin >> N >> K;
    for (int i = 0; i < K; i++)
    {
        cin >> T[i] >> X[i] >> Y[i];
    }
    solve();
    system("pause");
    return 0;
}