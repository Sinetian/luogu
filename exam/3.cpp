#include <iostream>
#include <algorithm>
using namespace std;
#define int long long
const int NR = 2e5 + 10;
int n, k, k1, ans, lastmax = -1, a[NR];
bool chk(int x)
{
	int cnt = 0;
	for(int i = 1; i <= n; i++) cnt += a[i] / x;
	return cnt >= k1;
}
signed main()
{
	cin >> n >> k;
	k1 = k * 2;
	for(int i = 1; i <= n; i++) 
	{
		cin >> a[i];
		lastmax = max(lastmax, a[i]);
	}
	if(k == 0)
	{
		cout << lastmax << endl; 
		return 0;
	}
	int l = 1, r = 1e9;
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