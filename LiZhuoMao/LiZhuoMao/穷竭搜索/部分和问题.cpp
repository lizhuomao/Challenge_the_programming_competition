#include <iostream>
using namespace std;
int N, K;
int num[20 + 5];
bool dfs(int i, int sum)
{
    if (i == N) return sum == K;
    if (dfs(i + 1, sum)) return true;
    if (dfs(i + 1, sum + num[i])) true;
}

void solve()
{
    if (dfs(0, 0)) printf("yes");
    else printf("no");
}

int main(void)
{
    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> num[i];
    solve();
    system("pause");
    return 0;
}