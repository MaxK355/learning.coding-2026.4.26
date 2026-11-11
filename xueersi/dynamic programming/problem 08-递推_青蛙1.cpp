#include <iostream>
using namespace std;
int main()
{
    long long f[100005];
    int h[100005];
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> h[i];
    }
    f[1] = 0;
    f[2] = abs(h[2] - h[1]);
    for(int i = 3;i <= n;i++)
    {
        int x = f[i - 1] + abs(h[i] - h[i - 1]);
        int y = f[i - 2] + abs(h[i] - h[i - 2]);
        f[i] = min(x,y);
    }
    cout << f[n];
    return 0;
}