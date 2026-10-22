#include <iostream>
#include <algorithm>
using namespace std;

int n, a[200005];
long long k;

bool check(int x)
{
     long long cnt = 0;
     for(int i = 0;i < n;i++)
     {
         cnt += (a[i] + x - 1) / x - 1;
         if(cnt > k)
         {
             return false;
         }
     }
     return true;
}

int main()
{
    cin >> n >> k;
    for(int i = 0;i < n;i++)
    {
        cin >> a[i];
    }
    int l = 1, r = 1e9,mid,ans = 0;
    while(l <= r)
    {
        mid = (l + r) >> 1;
        if(check(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << ans;
}