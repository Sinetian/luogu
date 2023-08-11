#include <iostream>
#include <algorithm>
using namespace std;
int a[1005], c[1005];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        c[i] = abs(a[i] - a[i + 1]);
    sort(c + 1, c + n);
    for (int i = 1; i < n; i++)
    {
        if (c[i] != i)
        {
            cout << "Not jolly" << endl;
            return 0;
        }
    }
    cout << "Jolly" << endl;
    return 0;
}