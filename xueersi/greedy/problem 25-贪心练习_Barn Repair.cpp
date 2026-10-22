#include <iostream>
using namespace std;

int n, h[100005], cnt;

int main()
{
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> h[i];
        if(h[i] > h[i - 1])
        {
            cnt += h[i] - h[i - 1];
        }
    }
    cout << cnt;
    return 0;
}