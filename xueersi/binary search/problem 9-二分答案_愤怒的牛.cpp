#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,m,x[100005];

bool check(int y)
{
    ll cnt = 1;
    ll last = x[0];
    if(y == 0) return true;
    for(int i = 0;i < n;i++)
    {
        if(x[i] - last >= y)
        {
            cnt++;
            last = x[i];
        }
    }
    return cnt >= m;
}

int main(){
	cin >> n >> m;
	for(int i = 0;i < n;i++)
	{
	    cin >> x[i];
	}
	sort(x,x + n);
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