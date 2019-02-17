#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;
const int MAX_N = 800 + 5;
int n, v1[MAX_N], v2[MAX_N];

void sovle()
{
    sort(v1, v1 + n);
    sort(v2, v2 + n);
    int ans = 0;
    for (int i = 0; i < n; i++) ans += (ll)v1[i] * v2[n - i - 1];
    cout << ans << endl;
    return;
}

int main(void)
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> v1[i];
    for (int i = 0; i < n; i++) cin >> v2[i];
    sovle();
    system("pause");
    return 0;
}