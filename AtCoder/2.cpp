#include <iostream>
using namespace std;
bool isPrime(int x)
{
    for(int i = 2; i * i <= x; i++)
    {
        if(x % i == 0) return false;
    }
    return true;
}
int main()
{
    int a, b;
    cin >> a >> b;
    if(!isPrime(a * b)) cout << "Even" << endl;
    else cout << "Odd" << endl;
    return 0;
}