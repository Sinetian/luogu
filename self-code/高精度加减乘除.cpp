#include <iostream>
using namespace std;
int a[114514], b[114514], c[114514];
//加
void readBIG(string s, int a[])
{
    int len = s.size();
    for(int i = 1; i <= len; i++) a[i] = s[len - i] - '0';
    a[0] = len;
}
void printBIG(int a[])
{
    int len = a[0];
    for(int i = len; i >= 1; i--) cout << a[i];
    cout << endl;
}
void addBIG(int a[], int b[], int c[])
{
    c[0] = max(a[0], b[0]);
    int len = c[0];
    for(int i = 1; i <= len; i++) c[i] = a[i] + b[i];
    for(int i = 1; i <= len; i++)
    {
        if(c[i] >= 10)
        {
            c[i + 1] += c[i] / 10;
            c[i] %= 10;
        }
        if(c[len + 1] > 0) len++;
    }
    c[0] = len;
}
//减
bool cmpBIG(int a[], int b[])
{
	int la = a[0], lb = b[0];
	if(la != lb) return la < lb;
	for(int i = la; i >= 1; i--)
	{
		if(a[i] != b[i]) return a[i] < b[i];
	}
	return false;
}
void subBIG(int a[], int b[], int c[])
{
	c[0] = a[0];
	int len = c[0];
	for(int i = 1; i <= len; i++) c[i] = a[i] - b[i];
	for(int i = 1; i <= len; i++)
	{
		if(c[i] < 0)
		{
			c[i] += 10;
			c[i + 1]--;
		}
	}
	while(c[len] == 0 && len > 1) len--;
	c[0] = len;
}
//乘
void mulBIG(int a[], int b, int c[])
{
	c[0] = a[0];
	int len = c[0];
	for(int i = 1; i <= len; i++) c[i] = a[i] * b;
	for(int i = 1; i <= len; i++)
	{
		if(c[i] >= 10)
		{
			c[i + 1] += c[i] / 10;
			c[i] %= 10;
		}
	}
	while(c[c[0] + 1] > 0) // 重点：使用while循环进位
	{
		if(c[c[0] + 1] >= 10)
		{
			c[c[0] + 2] += c[c[0] + 1]/ 10;
			c[c[0] + 1] %= 10;
		}
		c[0]++;
	}
}
//除
void divBIG(int a[], int b, int c[])
{
	c[0] = a[0];
	int len = a[0];
	int r = 0;
	for(int i = len; i >= 1; i--)
	{
		int t = r * 10 + a[i]; // 重点：必须备份
		c[i] = t / b;
		r = t % b;
	}
	while(c[c[0]] == 0 && c[0] > 1) c[0]--;
}
int main()
{
    string s;
    int x;
    cin >> s;

    return 0;
}