#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,m,a[100005];

bool check(int y)
{
    int sum = 0;
    int cnt = 1;
    for(int i = 0;i < n;i++)
    {
        if(a[i] > y) return false;
        if(sum + a[i] > y)
        {
            cnt++;
            sum = a[i];
        }
        else
        {
            sum += a[i];
        }
    }
    return cnt <= m;
}

int main(){
	cin >> n >> m;
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