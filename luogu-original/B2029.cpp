#include <iostream>
using namespace std;
const double Pi = 3.14159;
int main()
{
    int r, h, v, ans;
    cin >> h >> r;
    v = Pi * r * r * h;
    if (20000 % (int)v != 0)
        ans = 20000 / (int)v + 1;
    else
        ans = 20000 / (int)v;
    cout << ans << endl;
    return 0;
}