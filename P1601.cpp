#include <iostream>
using namespace std;
int a[115514], b[114514], c[114514];
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