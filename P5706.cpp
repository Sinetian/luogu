#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    double t;
    int n;
    cin >> t >> n;
    printf("%.3lf\n%d", t / (n * 1.0), 2 * n);
    return 0;
}