#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

ll n, k, a[100005],b[100005];

bool check(int s)
{
    int cnt = 0;
    for(int i = 0;i < n;i++)
    {
        cnt += ((a[i] / s) * (b[i] / s));
    }
    return cnt >= k;
}

int main(){
	cin >> n >> k;
	for(int i = 0;i < n;i++)
	{
	    cin >> a[i] >> b[i];
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