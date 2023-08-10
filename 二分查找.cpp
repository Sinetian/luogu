#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int NR = 1e5 + 5;
long long a[NR];
int main()
{
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	sort(a + 1, a + n + 1);
	while(q--)
	{
		long long x;
		cin >> x;
		int l = 1, r = n;
		bool flag = true;
		while(l <= r)
		{
			long long mid = (l + r) / 2;
			if(a[mid] == x)
			{
				cout << "Yes" << endl;
				flag = false;
				break;
			}
			else if(a[mid] > x) r = mid - 1;
			else l = mid + 1;
		}
		if(flag) cout << "No" << endl;
	}
	return 0;
}