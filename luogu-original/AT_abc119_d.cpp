#include<cstdio>
#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
const int NR = 1e5 + 5;
int a, b, q;
int s[NR], t[NR];
signed main()
{
	cin >> a >> b >> q;
	for(int i = 1; i <= a; i++) cin >> s[i];
	for(int i = 1; i <= b; i++) cin >> t[i];
	for(int i = 1; i <= q; i++)
	{
		int x;
		cin >> x;
		int cnt1 = lower_bound(s + 1, s + a + 1, x) - s, cnt2 = lower_bound(t + 1, t + b + 1, x) - t;
		int ans = 9e18;
		if (cnt1 > 1 && cnt2 > 1) ans = min(ans, max(x - s[cnt1 - 1], x - t[cnt2 - 1]));
		if (cnt1 <= a && cnt2 <= b) ans = min(ans, max(s[cnt1] - x, t[cnt2] - x));
		if (cnt1 > 1 && cnt2 <= b) ans = min(ans, min(x - s[cnt1 - 1] + t[cnt2] - s[cnt1 - 1], t[cnt2] - x - s[cnt1 - 1] + t[cnt2]));
		if(cnt1 <= a && cnt2 > 1) ans = min(ans, min(s[cnt1] - x + s[cnt1] - t[cnt2 - 1], x - t[cnt2 - 1] - t[cnt2 - 1] + s[cnt1]));
		cout << ans << endl;
	}
	return 0;
}