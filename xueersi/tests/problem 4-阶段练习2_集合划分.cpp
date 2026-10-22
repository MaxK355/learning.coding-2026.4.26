#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
long long a[50005], gap[50005], ans = 0;

bool cmp(long long x,long long y)
{
    return x < y;
}

bool cmp1(long long a, long long b)
{
    return a > b;
}

int main(){
    cin >> n >> k;
    for(int i = 0;i < n;i++)
    {
        cin >> a[i];
    }
    sort(a, a + n, cmp);
    for(int i = 0;i < n - 1;i++)
    {
        gap[i] += a[i + 1] - a[i];
    }
    sort(gap, gap + n - 1, cmp1);
    for(int i = 0;i < n - 1;i++)
    {
        ans += gap[i];
    }
    for(int i = 0;i < k - 1;i++)
    {
        ans -= gap[i];
    }
    cout << ans;
    return 0;
}