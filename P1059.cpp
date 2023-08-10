#include <iostream>
#include <algorithm>
using namespace std;
int cnt , box[1005];
int main()
{
    int n, x;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        if (box[x] > 0)
            continue;
        box[x]++;
        cnt++;
    }
    cout << cnt << endl;
    for (int i = 1; i <= 1000; i++)
        if (box[i] > 0)
            cout << i << " ";
    cout << endl;
    return 0;
}