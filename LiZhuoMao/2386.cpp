#include <iostream>
using namespace std;
int N, M;
char field[101][101];

void dfs(int x, int y)
{
    field[x][y] = '.';
    for (int dx = -1; dx <= 1; dx++)
    {
        for (int dy = -1; dy <= 1; dy++)
        {
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && ny >= 0 && nx < N && ny < M && field[nx][ny] == 'W') dfs(nx, ny);
        }
    }
}

void solve()
{
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (field[i][j] == 'W') { dfs(i, j), cnt++;};
        }
    }
    cout << cnt <<endl;
}

int main(void)
{
    cin >> N >> M;
    getchar();
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> field[i][j];
        }
    }
    solve();
    system("pause");
    return 0;
}