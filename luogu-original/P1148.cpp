#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int n, sum[10005][17], number;
int Fs[17] = {0, -50, -2, -3, -4, -5, -6, -7, -8, -9, -10, -20, -30, -40, -100, 100};
char s;
int main()
{
    while (true)
    {
        int Tot = 0, curans = 0;
        memset(sum, 0, sizeof(sum));
        for (int i = 1; i <= 4; i++)
        {
            cin >> n;
            Tot += n;
            for (int j = 1; j <= n; j++)
            {
                cin >> s >> number;
                if (s == 'H')
                    sum[i][number] = 1;
                if (s == 'S')
                    sum[i][14] = 1;
                if (s == 'C')
                    sum[i][16] = 1;
                if (s == 'D')
                    sum[i][15] = 1;
            }
        }
        if (Tot == 0)
            return 0;
        for (int i = 1; i <= 4; i++)
        {
            bool flag = 1;
            curans = 0;
            for (int j = 1; j <= 13; j++)
                if (sum[i][j] == 0)
                {
                    flag = false;
                    break;
                }
            if (flag)
            {
                if (sum[i][14] && sum[i][15])
                    curans += 500;
                else
                    curans += 200 + ((sum[i][14]) ? 1 : 0) * Fs[14] + ((sum[i][15]) ? 1 : 0) * Fs[15];
                if (sum[i][16])
                    curans *= 2;
                if (curans > 0)
                    printf("+%d ", curans);
                else
                    printf("%d ", curans);
            }
            else
            {
                flag = true;
                for (int j = 1; j <= 15; j++)
                    if (sum[i][j])
                    {
                        flag = false;
                        break;
                    }
                if (flag)
                {
                    if (sum[i][16])
                        printf("+50 ");
                    else
                        printf("0 ");
                }
                else
                {
                    for (int j = 1; j <= 15; j++)
                        curans += ((sum[i][j]) ? 1 : 0) * Fs[j];
                    if (sum[i][16])
                        curans *= 2;
                    if (curans > 0)
                        printf("+%d ", curans);
                    else
                        printf("%d ", curans);
                }
            }
        }
        cout << endl;
    }
    return 0;
}