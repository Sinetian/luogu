#include <iostream>
#include <algorithm>
using namespace std;
int a[205];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int k, p = 0;
        cin >> k;
        while (k % 2 == 0)
        {
            p++;
            k /= 2;
        }
        a[i] = p;
    }
    sort(a, a + n); // 排序
    cout << a[0] << endl;
    return 0;
}
