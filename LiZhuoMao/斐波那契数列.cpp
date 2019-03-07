#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;
typedef long long ll;
const int m = 10000;
ll n;

mat mul(mat &a, mat &b)
{
    mat c(a.size(), vec(b[0].size()));
    for (int i = 0; i < a.size(); i++)
    {
        for (int k = 0; k < b.size(); k++)
        {
            for (int j = 0; j < b[0].size(); j++)
            {
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % m;
            }
        }
    }
    return c;
}
mat pow(mat a, ll n)
{
    mat b(a.size(), vec(a.size()));
    for (int i = 0; i < a.size(); i++) b[i][i] = 1;
    while (n > 0)
    {
        if (n & 1) b = mul(a, b);
        a = mul(a, a);
        n >>= 1;
    }
    return b;
}
void solve()
{
    mat a(2, vec(2));
    a[0][0] = 1;
    a[0][1] = 1;
    a[1][0] = 1;
    a[1][1] = 0;
    a = pow(a, n);
    cout << a[1][0] << endl;
    return;
}

int main(void)
{
    cin >> n;
    solve();
    system("pause");
    return 0;
}