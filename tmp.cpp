#include <iostream>
#include <algorithm>
using namespace std;
int a[15], b[15];
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
// 读入
void readBIG(string s, int a[])
{
	int len = s.size();
	for(int i = 1; i <= len; i++) a[i] = s[len - i] - '0';
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