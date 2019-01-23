#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 10000 + 5;
int X[MAX_N], N, R;

void solve()
{
    sort(X, X + N);
    int i = 0, ans = 0;
    while (i < N)
    {
        int s = X[i++];
        while (i < N && X[i] <= s + R) i++;
        int t = X[i - 1];
        while (i < N && X[i] <= t + R) i++;
        ans++;
    }
    cout << ans << endl;
    return;
}

int main(int argc, char const *argv[])
{
    while (cin >> R >> N && R != -1 && N != -1)
    {
        for (int i = 0; i < N; i++) cin >> X[i];
        solve();
    }
    system("pause");
    return 0;
}
