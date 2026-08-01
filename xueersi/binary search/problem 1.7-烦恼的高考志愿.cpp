#include <iostream>
#include <algorithm>
using namespace std;

int m,n,a[100005],b[100005];
long long cnt = 0;

int f(int a[],int b)
{
    int r = upper_bound(a, a + m, b) - a;
    int l = lower_bound(a, a + m, b) - a;

    if(l < m && a[l] == b)
    {
        return 0;
    }

    if(r == m)
    {
        return b - a[m-1];
    }
    if(l == 0)
    {
        return a[0] - b;
    }
    return min(a[r] - b, b - a[l-1]);
}

int main()
{
    cin >> m >> n;
    for(int i = 0;i < m;i++)
    {
        cin >> a[i];
    }
    for(int i = 0;i < n;i++)
    {
        cin >> b[i];
    }
    sort(a,a + m);
    for(int i = 0;i < n;i++)
    {
        cnt = cnt + f(a,b[i]);
    }
    cout << cnt;
    return 0;
}