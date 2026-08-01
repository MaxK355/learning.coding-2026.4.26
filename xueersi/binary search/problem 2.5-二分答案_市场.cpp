#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,m,a[1000005],b[1000005];

bool check(ll &y)
{
    int ca = upper_bound(a + 1,a + n + 1,y) - a - 1;
    int cb = m - (lower_bound(b + 1,b + m + 1,y) - b) + 1;
    return ca >= cb;
}

int main(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
	    cin >> a[i];
	}
	for(int i = 1;i <= m;i++)
	{
	    cin >> b[i];
	}
	sort(a + 1,a + n + 1);
	sort(b + 1,b + m + 1);
	ll l = 1,r = 1e18, mid;
	while(l <= r)
	{
	    mid = (l + r) >> 1;
	    if(check(mid))
	    {
	        r = mid - 1;
	    }
	    else
	    {
	        l = mid + 1;
	    }
	}
	cout << l;
	return 0;
}