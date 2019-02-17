#include <iostream>
#include <vector>
using namespace std;

const int MAX_V = 0x7fffffff;
vector<int> G[MAX_V];
int V, color[MAX_V];

bool dfs(int v, int c)
{
    color[v] = c;
    for (int i = 0; i < G[v].size(); i++)
    {
        if (color[G[v][i]] == c) return false;
        if (color[G[v][i]] == 0 && !dfs(G[v][i], -c)) return false;
    }
    return true;
}
void solve()
{
    for (int i = 0; i < V; i++)
    {
        if (color[i] == 0)
        {
            if (!dfs(i, 1))
            {
                cout << "No" << endl;
                return;
            }
        }
    }
    cout << "Yes" << endl;
    return;
}

int main(void)
{
    return 0;
}