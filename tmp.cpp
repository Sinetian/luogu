#include <iostream>
#include <algorithm>
using namespace std;
int a[15], b[15];
void swapBIG(int a[], int b[])
{
    for (int i = 1; i <= n; i++)
    {
        if (x < h[i])
            return false;
        t[i - 1] = (x - h[i]) / s[i];
    }
    sort(t, t + n);
    for (int i = 0; i < n; i++)
        if (t[i] < i)
            return false;
    return true;
}
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
int main()
{
    string sa, sb;
    cin >> sa >> sb;
    readBIG(sa, a);
    readBIG(sb, b);
    swapBIG(a, b);
    printBIG(a);
    return 0;
}