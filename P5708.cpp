#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int main()
{
    double a, b, c;
    cin >> a >> b >> c;
    double p = 0.5 * (a + b + c);
    double s = sqrt(p * (p - a) * (p - b) * (p - c));
    printf("%.1lf", s);
    return 0;
}