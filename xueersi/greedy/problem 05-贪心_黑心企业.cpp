#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

long long p[300005], w[300005];
long long n,m,k;
int main(){
	cin >> n>> m >> k;
	for(int i=1;i<=n;i++)
	{
	    cin >> p[i];
	}
	for(int i=1;i<=m;i++)
	{
	    cin >> w[i];
	}
	sort(p+1,p+n+1);
	sort(w+1,w+m+1);
	long long pos, ans =0;
	for(int i=1;i<=m;i++)
	{
	    while(p[pos] < w[i])
	    {
	        pos++;
	    }
	    ans += k * p[pos];
	    pos++;
	}
	cout <<ans;
	return 0;
}