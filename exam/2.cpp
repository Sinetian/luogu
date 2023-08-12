#include<iostream>
#include<algorithm>
using namespace std;
int n, a[25][150], maxn[150], maxnum;
// 读入
void readBIG(string s, int a[])
{
    int len = s.size();
    for (int i = 1; i <= len; i++)
        a[i] = s[len - i] - '0';
    a[0] = len;
}
// 输出
void printBIG(int a[])
{
    for (int i = a[0]; i >= 1; i--)
        cout << a[i];
    cout << endl;
}
// 比较
bool cmpBIG(int a[], int b[])
{
    int la = a[0], lb = b[0];
    if (la != lb)
        return la < lb;
    for (int i = la; i >= 1; i--)
    {
        if (a[i] != b[i])
            return a[i] < b[i];
    }
    return false;
}
// 新写的赋值函数，可以把a转移到b
void swapBIG(int a[], int b[])
{
	int len = max(a[0], b[0]);
	for (int i = 1; i <= len; i++)
    {
        if(i <= a[0]) swap(a[i], b[i]);
        else
        {
            a[0]++;
            b[0]--;
            swap(a[i], b[i]);
        }
    }
    int lena = a[0], lenb = b[0];
    while(a[lena] == 0 && lena > 1) lena--;
    while(b[lenb] == 0 && lenb > 1) lenb--;
    a[0] = lena;
    b[0] = lenb;
}
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		readBIG(s, a[i]);
	}
	for(int i = 1; i <= n; i++)
	{
		if(!cmpBIG(a[i], maxn))
		{
			maxn[0] = a[i][0];
			maxnum = i;
			swapBIG(a[i], maxn);
		}
	}
	cout << maxnum << endl;
	printBIG(maxn);
	return 0;
}