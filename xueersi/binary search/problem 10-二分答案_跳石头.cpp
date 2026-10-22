#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll len,n,m,d[50005];

bool check(int y)
{
    ll last = 0;
    int cnt = 0;
    if(y == 0) return true;
    for(int i = 1;i <= n + 1;i++)
    {
        if(d[i] - last >= y)
        {
            last = d[i];
        }
        else
        {
            cnt++;
        }
    }
    return cnt <= m;
}

int main(){
	cin >> len >> n >> m;
	for(int i = 1;i <= n;i++)
	{
	    cin >> d[i];
	}
	d[n + 1] = len;
	sort(d + 1,d + n + 1);
	ll l = 0,r = len, mid, ans = 0;
	while(l <= r)
	{
	    mid = (l + r) >> 1;
	    if(check(mid))
	    {
	        ans = mid;
	        l = mid + 1;
	    }
	    else
	    {
	        r = mid - 1;
	    }
	}
	cout << ans;
	return 0;
}