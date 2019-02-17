#include <functional>
#include <queue>
#include <iostream>
using namespace std;

const int MAX_N = 20000 + 5;
int N, L[MAX_N];

void solve()
{
    long long ans = 0L;
    priority_queue<int, vector<int>, greater<int>> que;
    for (int i = 0; i < N; i++)
    {
        que.push(L[i]);
    }
    while (que.size() > 1)
    {
        int l1 = que.top();
        que.pop();
        int l2 = que.top();
        que.pop();
        que.push(l1 + l2);
        ans += l1 + l2;
    }
    cout << ans << endl;
    return;
}

int main(void)
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> L[i];
    }
    solve();
    return 0;
}