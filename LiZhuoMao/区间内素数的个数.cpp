#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;
const ll MAX_L = 10e12, MAX_SQRT_B = 10e6;
bool is_prime[MAX_L], is_prime_small[MAX_SQRT_B];

void segment_sieve(ll a, ll b)
{
    for (int i = 0; (ll) i * i < b; i++) is_prime_small[i] = true;
    for (int i = 0; i < b - a; i++) is_prime[i] = true;
    for (int i = 2; (ll) i * i < b; i++)
    {
        if (is_prime_small[i])
        {
            for (int j = 2 * i; (ll) j * j < b; j += i) is_prime_small[j] = false;
            for (ll j = max(2LL, (a + i - 1) / i) * i; j < b; j += i) is_prime[j - a] = false;
        }
    }
    ll ans = 0;
    for (ll i = a; i < b; i++)
    {
        if (is_prime[i - a]) ans++;
    }
    cout << ans << endl;
    return;
}

int main(void)
{
    ll a, b;
    cin >> a >> b;
    segment_sieve(a, b);
    system("pause");
    return 0;
}