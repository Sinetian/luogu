#include <iostream>
#include <algorithm>
using namespace std;
#define int long long
const int NR = 2e5 + 10;
int n, k, ans, a[NR];
bool chk(int x)
{
	
}
signed main()
{
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
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
	return 0;
}