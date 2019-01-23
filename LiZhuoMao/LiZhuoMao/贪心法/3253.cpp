#include <iostream>
using namespace std;

const int MAX_N = 20000 + 5;
int L[MAX_N], N;

void solve()
{
    int ans = 0, i = 0;
    while (N > 1)
    {
        int min1 = 0, min2 = 1;
        if (L[min1] > L[min2]) swap(min1, min2);
        for (int i = 2; i < N; i++)
        {
            if (L[i] < L[min1])
            {
                min2 = min1;
                min1 = i;
            }
            else if (L[i] < L[min2])
            {
                min2 = i;
            }
        }
        int t = L[min1] + L[min2];
        ans += t;
        if (min1 == N - 1) swap(min1, min2);
        L[min1] = t;
        L[min2] = L[N - 1];
        N--;
    }
    cout << ans << endl;
    return;
}

int main(int argc, char const *argv[])
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> L[i];
    }
    solve();
    system("pause");
    return 0;
}
