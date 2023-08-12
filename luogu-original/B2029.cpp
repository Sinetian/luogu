#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
const double PI = 3.1415926;
double r, h, b;
int main()
{
    cin >> r >> h;
    b = 20000 / (PI * r * r * h);
    cout << ceil(b) << endl;
    return 0;
}
