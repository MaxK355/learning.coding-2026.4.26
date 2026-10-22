#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

ll n, m, a[1000005];

bool check(ll &h)
{
    ll sum = 0;
    for(int i = 0;i < n;i++)
    {
        if(a[i] > h)
        {
            sum = sum + (a[i] - h);
        }
    }
    return sum >= m;
}

int main(){
	cin >> n >> m;
	for(int i = 0;i < n;i++)
	{
	    cin >> a[i];
	}
	ll l = 0, r = 1e8, mid; 
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