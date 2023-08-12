#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int a[1145];
void outBIG(int a[])
{
	int len = a[0];
	for(int i = len; i >= 1; i--) cout << a[i];
	cout << endl;
}
void readBIG(string s, int a[])
{
	int len = s.size();
	for(int i = 1; i <= len; i++) a[i] = s[len - i] - '0';
	a[0] = len;
}
void timeBIG(int a[], int b, int c[])
{
	c[0] = a[0];
	int len = c[0];
	for(int i = 1; i <= len; i++) c[i] = a[i] * b;
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
int main() 
{
	int n, a1, cnt = 0;
	cin >> n >> a1;
	readBIG("1", a);
	for(int i = 1; i <= n; i++) timeBIG(a, i, a);
	for(int i = a[0]; i >= 1; i--)
    {
        if(a[i] == a1) cnt++;
    }
    cout << cnt << endl;
    return 0;
}