#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n, k, a[200005], cnt=0;
int main(){
	cin >> n >> k;
	for(int i = 1; i<=n;i++)
	{
	    cin >>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=n;
	while(l<=r)
	{
	    if(a[l] + a[r] <= k)
	    {
	        l++;
	        r--;
	        cnt++;
	    }
	    else
	    {
	        r--;
	        cnt++;
	    }
	}
	cout << cnt;
	return 0;
}