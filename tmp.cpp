#include <iostream>
using namespace std;
int a[1100], b[1100], c[1100];
// 读入
void readBIG(string s, int a[])
{
    int len = s.size();
    for (int i = 1; i <= len; i++)
        a[i] = s[len - i] - '0'; // 从高位开始读入
    a[0] = len;
}
// 输出
void printBIG(int a[])
{
    for (int i = a[0]; i >= 1; i--)
        cout << a[i]; // 因为是反向读入，所以得反过来输出
    cout << endl;
}
// 加法
void addBIG(int a[], int b[], int c[])
{
    c[0] = max(a[0], b[0]);
    for(int i = 1; i <= c[0]; i++) c[i] = a[i] + b[i];
    for(int i = 1; i <= c[0]; i++)
    {
        if(c[i] >= 10)
        {
            c[i + 1] += c[i] / 10;
            c[i] %= 10;
        }
        if(c[c[0] + 1] > 0) c[0]++;
    }
}
// 减法比较，返回较小值
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
// 减法
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
	while(c[len] == 0 && len > 1) len--; // 删除前导0
	c[0] = len;
}
//乘法(高 * 单)
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
//除法(高 / 单)
void divBIG(int a[], int b[], int c[])
{
    c[0] = a[0];
    int len = c[0], r = 0;
    for(int i = len; i >= 1; i--)
	{
		int t = r * 10 + a[i]; // 重点：必须备份
		c[i] = t / b[i];
		r = t % b[i];
	}
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    readBIG(s1, a);
    readBIG(s2, b);
    addBIG(a, b, c);
    printBIG(c);
    return 0;
}