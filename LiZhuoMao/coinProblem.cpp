#include <iostream>
#include <algorithm>
using namespace std;
const int V[6] = {1, 5, 10, 50, 100, 500};
int C[6] = {0}, A = 0;

void solve()
{
    int ans = 0;
    for (int i = 5; i >= 0; i--)
    {
        int t = min(A / V[i], C[i]);
        A -= t * V[i];
        ans += t;
    }
    cout << ans << endl;
    return;
}

int main(void)
{
    for (int i = 0; i < 6; i++)
    {
        cin >> C[i];
    }
    cin >> A;
    solve();
    system("pause");
    return 0;
}