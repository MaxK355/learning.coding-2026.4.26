#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string s;
int main()
{
	cin >> s;
	int dp[55];
	int len = s.size();
	s = " " + s;
	dp[0] = 1;
	dp[1] = 1;
	for(int i = 2;i <= len;i++)
	{
	    int num = (s[i-1] - '0')*10+(s[i] - '0');
	    if(num >= 10 && num <= 25)
	    {
	        dp[i] = dp[i - 1] + dp[i - 2];
	    }
	    else
	    {
	        dp[i] = dp[i - 1];
	    }
	}
	cout << dp[len];
	return 0;
}