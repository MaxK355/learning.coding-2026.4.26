#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,k,a[100005];

bool check(int x)
{
    ll cnt = 0;
    if(x == 0) return true;
    for(int i = 0;i < n;i++)
    {
        cnt += a[i] / x;
    }
    return cnt >= k;
}

int main(){
	cin >> n >> k;
	for(int i = 0;i < n;i++)
	{
	    cin >> a[i];
	}
	ll l = 0,r = 1e9, mid;
	while(l <= r)
	{
	    mid = (l + r) >> 1;
	    if(check(mid))
	    {
	        l = mid + 1;
	    }
	    else
	    {
	        r = mid - 1;
	    }
	}
	cout << r;
	return 0;
}