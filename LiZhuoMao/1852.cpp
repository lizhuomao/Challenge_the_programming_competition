#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int N;
    cin >> N; 
    for (int i = 0; i < N; i++)
    {
        int L, cnt;
        cin >> L >> cnt;
        vector<int> v(cnt);
        for (int j = 0; j < cnt; j++)
        {
            cin >> v[j];
        }
        int minT = 0, maxT = 0;
        for (int j = 0; j < cnt; j++)
        {
           // cout << v[j] << " " << min(v[j], L - v[j]);
            minT = max(minT, min(v[j], L - v[j]));
            //cout << minT << "!";
        }
        for (int j = 0; j < cnt; j++)
        {
            maxT = max(maxT, max(L - v[j], v[j]));
            //cout << maxT << " ";
        }
        printf("%d %d\n", minT, maxT);
    }
    system("pause");
    return 0;
}