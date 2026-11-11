#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

long long max(long long x, long long y)
{
    if(x > y) 
    {
        return x;
    }
    return y;
}

long long min(long long x, long long y)
{
    if(x < y) 
    {
        return x;
    }
    return y;
}

int a[100005];
long long prefix_sum[100005]; 
long long ans[100005];

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    
    prefix_sum[n] = a[n];
    long long minn = min(0, prefix_sum[n]); 
    ans[n] = prefix_sum[n]; 
    for(int i = n-1; i >= 1; i--)
    {
        prefix_sum[i] = prefix_sum[i + 1] + a[i];
        ans[i] = max(prefix_sum[i] - minn, ans[i + 1]);
        minn = min(prefix_sum[i], minn);
    }
    for(int i = 0; i < m; i++)
    {
        int pos;
        cin >> pos;
        cout << ans[pos] << endl;
    }

    return 0;
}
