#include <iostream>
#include <algorithm>
using namespace std;
int a[15][15];
bool flag1[15][15], flag2[15][15], flag3[15][15], isFind;
int m[10][10] = 
{
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 1, 1, 2, 2, 2, 3, 3, 3},
	{0, 1, 1, 1, 2, 2, 2, 3, 3, 3},
	{0, 1, 1, 1, 2, 2, 2, 3, 3, 3},
	{0, 4, 4, 4, 5, 5, 5, 6, 6, 6},
	{0, 4, 4, 4, 5, 5, 5, 6, 6, 6},
	{0, 4, 4, 4, 5, 5, 5, 6, 6, 6},
	{0, 7, 7, 7, 8, 8, 8, 9, 9, 9},
	{0, 7, 7, 7, 8, 8, 8, 9, 9, 9},
	{0, 7, 7, 7, 8, 8, 8, 9, 9, 9}
};
void dfs(int x, int y)
{
	if(x == 10 && y == 1)
	{
		for(int i = 1; i <= 9; i++)
		{
			for(int j = 1; j <= 9; j++) cout << a[i][j] << " ";
			cout << endl;
			return;
		}
	}
    int xnew = x, ynew = y + 1;
	if(ynew == 10) xnew++, ynew = 1;
	if(a[x][y] != 0) dfs(xnew, ynew);
	else
	{
		for(int i = 1; i <= 9; i++)
		{
			if(flag1[x][i] || flag2[y][i] || flag3[m[x][y]][i]) continue;
			flag1[x][i] = true;
			flag2[y][i] = true;
			flag3[m[x][y]][i] = true;
			a[x][y] = i;
			dfs(xnew, ynew);
			flag1[x][i] = false;
			flag2[y][i] = false;
			flag3[m[x][y]][i] = false;
			a[x][y] = 0;
		}
	}
	return;
}
int main()
{
	for(int i = 1; i <= 9; i++)
	{
		for(int j = 1; j <= 9; j++) 
		{
			cin >> a[i][j];
			flag1[i][a[i][j]] = true;
			flag2[j][a[i][j]] = true;
			flag3[m[i][j]][a[i][j]] = true;
		}
	}
	dfs(1, 1);
	return 0;
}