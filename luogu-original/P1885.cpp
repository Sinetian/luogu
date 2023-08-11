#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
long long s[30];
int n;
char f(int k , int x)
{
	if(k == 0)
	{
		if(x == 1) return 'm';
		else return 'o';
	}
	if(s[k - 1] >= x) return f(k - 1 , x);
	x -= s[k - 1];
	if(x == 1) return 'm';
	if(x <= k + 3) return 'o';
	return f(k - 1 , x - k - 3);
}
int main()
{
	s[0] = 3;
	for(int i = 1; i <= 28; i++) s[i] = s[i - 1] * 2 + i + 3;
	cin >> n;
	cout << f(28 , n) << endl;
	return 0;	
}