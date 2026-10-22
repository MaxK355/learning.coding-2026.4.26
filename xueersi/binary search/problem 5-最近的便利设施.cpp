#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int a,b,q;
ll s[100005],t[100005];

ll f(ll arr[],ll n,ll x)
{
    int p = lower_bound(arr, arr + n,x) - arr;
    ll minx = 1e18;
    if(p < n)
    {
        minx = min(minx, arr[p] - x);
    }
    if(p > 0)
    {
        minx = min(minx, x - arr[p - 1]);
    }
    return minx;
}
int main()
{
    cin >> a >> b >> q;
    for(int i = 0;i < a;i++)
    {
        cin >> s[i];
    }
    for(int i = 0;i < b;i++)
    {
        cin >> t[i];
    }
    sort(s,s + a);
    sort(t,t + b);
    while (q--)
    {
        ll x;
        cin >> x;
        cout << min(f(s,a,x),f(t,b,x)) << endl;
    }
    return 0;
}