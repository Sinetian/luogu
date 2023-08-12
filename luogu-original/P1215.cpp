#include <iostream>
#include <algorithm>
using namespace std;
int tot[25];
bool ans[25], vis[25][25][25];
void dfs(int x, int y, int z)
{
	if(vis[x][y][z]) return;
	vis[x][y][z] = true;
	if(x == 0) ans[z] = true;
	int num[] = {0,x,y,z};
	for(int i = 1; i <= 3; i++)
	{
		for(int j = 1; j <= 3; j++)
		{
			if(i == j) continue;
			if(num[i] == 0 && num[j] == tot[j]) continue;
			int tmpdoit = min(num[i], abs(num[j] - tot[j]));
			num[i] -= tmpdoit;
			num[j] += tmpdoit;
			dfs(num[1], num[2], num[3]);
			num[i] += tmpdoit;
			num[j] -= tmpdoit;
		}
	}
}
int main()
{
	for(int i = 1; i <= 3; i++) cin >> tot[i];
	dfs(0, 0, tot[3]);
	for(int i = 0; i <= 20 ;i++)
	{
		if(ans[i]) cout << i << " ";
	}
    return 0;
}