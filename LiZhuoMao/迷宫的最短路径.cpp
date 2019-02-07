/*
10 10
#S######.#
......#..#
.#.##.##.#
.#........
##.##.####
....#....#
.#######.#
....#.....
.####.###.
....#...G#
*/

#include <queue>
#include <iostream>
using namespace std;
int N, M;
char field[101][101];
typedef pair<int, int> P;
int sx, sy, ex, ey;
int d[101][101];
int INF = 10000000;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int bfs(void)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            d[i][j] = INF;
    }
    queue<P> Q;
    Q.push(P(sx, sy));
    d[sx][sy] = 0;
    while (Q.size())
    {
        P p = Q.front(); Q.pop();
        if (p.first == ex && p.second == ey) break;
        for (int i = 0; i < 4; i++)
        {
            int nx = p.first + dx[i], ny = p.second + dy[i];
            if (nx >=0 && ny >= 0 && nx < N && ny < M && field[nx][ny] != '#' && d[nx][ny] == INF)
            {
                Q.push(P(nx, ny));
                d[nx][ny] = d[p.first][p.second] + 1;
            }
        }
    }
    return d[ex][ey];
}

void solve()
{
    cout << bfs() << endl;
}

int main(void)
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> field[i][j];
            if (field[i][j] == 'S') { sx = i; sy = j;}
            if (field[i][j] == 'G') { ex = i; ey = j;}
        }
    }
    solve();
    system("pause");
    return 0;
}