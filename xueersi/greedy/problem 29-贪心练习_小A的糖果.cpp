#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,x,a[100005];
long long cnt;

int main() {
	cin >> n >> x;
	for(int i = 1;i <= n;i++)
	{
	    cin >> a[i];
	    if(a[i] > x)
	    {
	        cnt += a[i] - x;
	        a[i] = x;
	    }
	}
	for(int i = 1;i < n;i++)
	{
	    if(a[i] + a[i+1] > x)
	    {
	        cnt += a[i] + a[i+1] - x;
	        a[i+1] = x - a[i];
	    }
	}
	cout << cnt;
    return 0;
}