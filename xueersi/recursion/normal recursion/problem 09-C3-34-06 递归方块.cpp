#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int sum = 0;
    for(int i = n;i >= 1;i--)
    {
        sum += ((i * i) + i)/2;
    }
    cout << sum;
    
// 或者：
//
//int rec(int n)
//{
//     if(n == 1)
//     {
//         return 1;
//     }
//     return rec(n - 1) + (n * n + n)/2;
//}

    return 0;
}