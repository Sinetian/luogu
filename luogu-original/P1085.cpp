#include <iostream>
using namespace std;
int a, b, sum, maxx = 0, day = 0;
int main()
{
    for (int i = 1; i < 8; i++)
    {
        cin >> a >> b;
        sum = a + b;
        if (maxx > sum && sum > 8) maxx = max(sum , maxx), day = i;
    }
    cout << day << endl;
    return 0;
}