#include <iostream>
using namespace std;

const int MAX_N = 10e6;
int prime[MAX_N];
bool is_prime[MAX_N + 1];

int solve(int n)
{
    int p = 0;
    for (int i = 0; i <= n; i++) is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i])
        {
            prime[p++] = i;
            for (int j = i * 2; j <= n; j += i) is_prime[j] = false;
        }
    }
    return p;
}

int main(void)
{
    int n;
    cin >> n;
    n = solve(n);
    cout << n << endl;
    system("pause");
    return 0;
}