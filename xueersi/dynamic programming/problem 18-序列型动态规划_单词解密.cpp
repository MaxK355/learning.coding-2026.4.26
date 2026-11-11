#include <iostream>
#include <string>
using namespace std;
string s;
long long dp[100005];
int main() 
{
    cin >> s;
    int len = s.size();
    dp[0] = 1; 
    dp[1] = 1; 
    for (int i = 2; i <= len; i++) 
    {
        if (s[i - 1] != '0') 
        {
            dp[i] = (dp[i] + dp[i - 1]) % 1000000007;
        }
        int num = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
        if (num >= 10 && num <= 26) 
        {
            dp[i] = (dp[i] + dp[i - 2]) % 1000000007;
        }
    }
    cout << dp[len] << endl;
    return 0;
}
