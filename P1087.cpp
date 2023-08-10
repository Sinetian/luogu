#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
char search(string s) {
	if(s.size() == 1)
	{
		char c;
		if(s[0] == '1') c = 'I';
		else c = 'B';
		cout << c;
		return c;
	}
	char c1 = search(s.substr(0 , s.size() / 2));
	char c2 = search(s.substr(s.size() / 2));
	char c;
	if(c1 == 'I' && c2 == 'I') c = 'I';
	else if(c1 == 'B' && c2 == 'B') c = 'B';
	else c = 'F';
	cout << c;
	return c;
}
int n;
string s;
int main() {
	cin >> n >> s;
	search(s);
	return 0;
}