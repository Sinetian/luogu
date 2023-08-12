#include <iostream>
#include <string.h>
using namespace std;
long long fastCal(long long a, long long b, long long p)
{
	long long mul = 1;
	while(b)
	{
		if(b & 1) mul = mul * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return mul;
}
int main()
{
    int Q;
    cin >> Q;
    while(Q--)
    {
        int x, y, mod;
        cin >> x >> y >> mod;
        cout << fastCal(x, y, mod) << endl;
    }
    return 0;
}