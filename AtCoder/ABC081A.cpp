#include <iostream>
using namespace std;
int main()
{
    string s;
    int cnt = 0;
    cin >> s;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '1') cnt++;
    }
    cout << cnt << endl;
    return 0;
}