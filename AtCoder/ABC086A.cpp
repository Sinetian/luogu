#include <iostream>  //头文件
using namespace std; // 名字空间
int main()
{
    int a, b;
    cin >> a >> b;
    if (a % 2 == 1 && b % 2 == 1) // 判断它们是否都是奇数
        cout << "Odd";            // 输出“Odd”
    else
        cout << "Even"; // “输出Even”
    return 0;
}