#include <iostream>
#include <algorithm>
using namespace std;
#define int long long
const int NR = 1e5 + 5;
int n, ans, h[NR], s[NR], t[NR];
bool chk(int x)
{
    for (int i = 1; i <= n; i++)
    {
        if (x < h[i])
            return false;
        t[i - 1] = (x - h[i]) / s[i]; // 更新秒数
    }
    sort(t, t + n);
    for (int i = 0; i <= n; i++)
        if (t[i] < i)
            return false;
    return true;
}
signed main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> h[i] >> s[i];
    int l = 1, r = 2e6;
    while(l < r)
    {
        int mid = (l + r) / 2;
        if(chk(mid))
        {
            r = mid;
            ans = mid;
        }
        else l = mid + 1;
    }
    cout << ans << endl;
    return 0;
}