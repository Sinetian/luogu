#include <iostream>
#include <algorithm>
using namespace std;
#define int long long
const int NR = 1e5 + 5;
int n, ans, h[NR], s[NR], t[NR];
bool chk(int x)
{
    if(x < h[1]) return false; // 循环从2开始，所以得单独判断
    for (int i = 2; i <= n; i++)
    {
        if (x < h[i])
            return false;
        t[i - 1] = (x - h[i]) / s[i];
    }
    sort(t + 1, t + 1 + n);
    for (int i = 1; i <= n; i++)
        if (t[i] < i)
            return false;
    return true;
}
signed main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> h[i] >> s[i];
    int l = 1, r = 1e6;
    while(l <= r)
    {
        int mid = (l + r) / 2;
        if(chk(mid))
        {
            l = mid + 1;
            ans = mid;
        }
        else r = mid - 1;
    }
    cout << ans << endl;
    return 0;
}