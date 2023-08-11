#include <iostream>
#include <string.h>
using namespace std;
bool a[10005];
int cnt;
int main()
{
    int l , m;
    cin >> l >> m;
    memset(a , true , sizeof(a));
    for(int i = 1; i <= m; i++)
    {
        int u , v;
        cin >> u >> v;
        for(int ij = u; ij <= v; ij++) a[ij] = false;
    }
    for(int i = 0; i <= l; i++)
    {
        if(a[i]) cnt++;
    }
    cout << cnt << endl;
    return 0;
}