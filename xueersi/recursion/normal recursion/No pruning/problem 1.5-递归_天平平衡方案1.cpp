#include <iostream>
using namespace std;

// a[i]：第 i 个砝码的放法：
// -1: 放在左盘
// 0：不放
// 1：放在右盘
int w[10], a[10], ans;

int main() 
{
    for (int i = 1; i <= 5; ++i)
        cin >> w[i];
    for (a[1] = -1; a[1] <= 1; ++a[1])
        for (a[2] = -1; a[2] <= 1; ++a[2])
            for (a[3] = -1; a[3] <= 1; ++a[3])
                for (a[4] = -1; a[4] <= 1; ++a[4])
                    for (a[5] = -1; a[5] <= 1; ++a[5]) 
                    {
                        //作答区域
                        int sum = 0;
                        for(int i = 1;i <= 5;i++)
                        {
                            sum += w[i] * a[i];
                        }
                        if(sum == 0)
                        {
                            ans++;
                        }
                    }
    cout << ans << endl;
    return 0;
}