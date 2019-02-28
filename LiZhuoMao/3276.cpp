#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 5000 + 5;
int n, dir[maxn], f[maxn];

int calc(int k)
{
    memset(f, 0, sizeof(f));
    int res = 0, sum = 0;
    for (int i = 0; i + k <= n; i++)
    {
        if ((dir[i] + sum) % 2 != 0)
        {
            res++;
            f[i] = 1;
        }
        sum += f[i];
        if (i - k + 1 >= 0) sum -= f[i - k + 1];
    }
    for (int i = n - k + 1; i < n; i++)
    {
        if ((dir[i] + sum) % 2 != 0)
        {
            return -1;
        }
        if (i - k + 1 >= 0)
        {
            sum -= f[i - k + 1];
        }
    }
    return res;
}
void solve()
{
    int K = 1, M = n;
    for (int k = 1; k <= n; k++)
    {
        int m = calc(k);
        if (M > m && m >= 0)
        {
            M = m;
            K = k;
        }
    }
    cout << K << " " << M << endl;
    return;
}

int main(void)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char temp;
        cin >> temp;
        dir[i] = temp == 'B' ? 1 : 0;
    }
    solve();
    system("pause");
    return 0;
}