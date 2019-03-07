#include <cmath>
#include <iostream>
using namespace std;

const int st_size = (1 << 15) - 1, maxn = 10000 + 5;
const double m_pi = 3.1415926;
int n, c, l[maxn], s[maxn], a[maxn];
double vx[st_size], vy[st_size], ang[st_size], prv[maxn];

void init(int k, int left, int right)
{
    ang[k] = vx[k] = 0.0;
    if (right - left == 1) vy[k] = l[left];
    else
    {
        int chl = k * 2 + 1, chr = k * 2 + 2;
        init(chl, left, (left + right) / 2);
        init(chr, (left + right) / 2, right);
        vy[k] = vy[chl] + vy[chr];
    }
    return;
}
void change(int s, double a, int v, int left, int right)
{
    if (s <= left) return;
    else if (s < right)
    {
        int chl = v * 2 + 1, chr = v * 2 + 2;
        change(s, a, chl, left, (left + right) / 2);
        change(s, a, chr, (left + right) / 2, right);
        cout << s << " l = " << left  << " r = " << right << " v = " << v << " a = " << a << endl;
        if (s <= (left + right) / 2) ang[v] += a;
        double s = sin(ang[v]), c = cos(ang[v]);
        vx[v] = vx[chl] + (c * vx[chr] - s * vy[chr]);
        vy[v] = vy[chl] + (s * vx[chr] + c * vy[chr]);
    }
    return;
}
void solve()
{
    init(0, 0, n);
    for (int i = 1; i < n; i++) prv[i] = m_pi;
    for (int i = 0; i < c; i++)
    {
        int s_ = s[i];
        double a_ = a[i] / 360.0 * 2 * m_pi;
        change(s_, a_ - prv[s_], 0, 0, n);
        prv[s_] = a_;
        printf("%.2f %.2f\n", vx[0], vy[0]);
    }
    return;
}

int main(void)
{
    cin >> n >> c;
    for (int i = 0; i < n; i++) cin >> l[i];
    for (int i = 0; i < c; i++) cin >> s[i];
    for (int i = 0; i < c; i++) cin >> a[i];
    solve();
    system("pause");
    return 0;
}