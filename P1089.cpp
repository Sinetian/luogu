#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int in, out, ans = 0, temp = 0, i = 1;
    while (i <= 12)
    {
        in = 300;
        cin >> out;
        temp = in + temp - out;
        if (temp < 0)
        {
            cout << "-" << i << endl;
            return 0;
        }
        ans = ans + (temp - temp % 100);
        temp = temp - (temp - temp % 100);
        i++;
    }
    // 打印奖励加上手上的总资产
    cout << int((ans)*1.2) + temp << endl;
    return 0;
}