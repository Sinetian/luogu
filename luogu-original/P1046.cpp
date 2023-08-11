#include <iostream>
using namespace std;
int a[11] , b , cnt;
int main()
{
    for(int i = 1; i <= 10; i++) cin >> a[i];
    cin >> b;
    for(int i = 1; i <= 10; i++)
    {
        if(b >= a[i]) cnt++;
        else if(b + 30 >= a[i]) cnt++;
    }
    cout << cnt << endl;
    return 0;
}