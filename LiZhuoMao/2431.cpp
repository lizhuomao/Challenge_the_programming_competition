#include <queue>
#include <iostream>
using namespace std;

const int MAX_N = 10000 + 5;
int N, L, P, A[MAX_N], B[MAX_N];

void solve()
{
    A[N] = L;
    B[N] = 0;
    N++;
    priority_queue<int> que;
    int ans = 0, pos = 0, tank = P;
    for (int i = 0; i < N; i++)
    {
        int d = A[i] - pos;
        while (tank - d < 0)
        {
            if (que.empty())
            {
                cout << "-1" << endl;
                return;
            }
            tank += que.top();
            que.pop();
            ans++;
        }
        tank -= d;
        pos = A[i];
        que.push(B[i]);
    }
    cout << ans;
    return;
}

int main(void)
{
    cin >> N ;//>> L >> P;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i] >> B[i];
    }
    cin >> L >> P;
    solve();
    system("pause");
    return 0;
}