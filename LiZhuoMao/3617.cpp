#include <iostream>
using namespace std;

const int MAX_N = 2000 + 5;
char S[MAX_N];
int N;

void solve()
{
    int a = 0, b = N - 1, count = 0;
    bool left = false;
    while (a <= b)
    {
        for (int i = 0; a + i <= b; i++)
        {
            if (S[a + i] < S[b - i])
            {
                left = true;                count++;
                break;
            }
            else if (S[a + i] > S[b - i])
            {
                left = false;
                break;
            }
        }
        count++;
        if (left) putchar(S[a++]);
        else putchar(S[b--]);
        if (count % 80 == 0) cout << endl;
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> S[i];
    }
    solve();
    system("pause");
    return 0;
}
