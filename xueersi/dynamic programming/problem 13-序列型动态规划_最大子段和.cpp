#include <iostream>
#include <cmath>
using namespace std;

long long min(long long x,long long y)
{
    if(x < y) 
    {
        return x;
    }
    return y;
}

long long max(long long x,long long y)
{
    if(x > y) 
    {
        return x;
    }
    return y;
}

int main()
{
    long long prefix_sum[100005];
    int a[100005];
    int n;
    long long ans = -1e18;
    long long minn = 1e18;
    cin >> n;
    cin >> a[1];
    prefix_sum[1] = a[1];
    minn = min(prefix_sum[1],minn);
    ans = max(prefix_sum[1] - minn, ans);
    for(int i = 2;i <= n;i++)
    {
        cin >> a[i];
        prefix_sum[i] = prefix_sum[i - 1] + a[i];
        minn = min(prefix_sum[i],minn);
        ans = max(prefix_sum[i] - minn, ans);
    }
    cout << ans;
    return 0;
}