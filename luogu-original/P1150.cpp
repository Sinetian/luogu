#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n , k;
    cin >> n >> k;
    cout << n + (n - 1) / (k - 1) << endl;
    return 0;
}