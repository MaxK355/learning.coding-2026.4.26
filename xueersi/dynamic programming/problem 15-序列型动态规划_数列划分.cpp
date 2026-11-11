#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int n,sum,a[1005],s[1005],dp[1005],mod = 1e9;
int main()
{
	cin >> n >> sum;
	for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    dp[0] = 1;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 0;j < i;j++)
        {
            if(s[i] -s[j] <= sum)
            {
                dp[i] = (dp[i] + dp[j]) % mod;
            }
        }
    }
    cout << dp[n];
	return 0;
}