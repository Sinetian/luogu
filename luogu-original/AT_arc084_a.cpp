#include <iostream>
#include <algorithm>
using namespace std;
#define int long long
const int NR = 1e5 + 5;
int a[NR], b[NR], c[NR];
signed main()
{
	int n;
	int ans = 0;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	for(int i = 1; i <= n; i++) cin >> c[i];
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	sort(c + 1, c + n + 1);
	for(int i = 1; i <= n; i++)
	{
		int cnt2 = upper_bound(c + 1, c + n + 1, b[i]) - c;
		int cnt1 = lower_bound(a + 1, a + n + 1, b[i]) - a - 1;
		ans += cnt1 * (n - cnt2 + 1);
	}
	cout << ans << endl;
	return 0;
}