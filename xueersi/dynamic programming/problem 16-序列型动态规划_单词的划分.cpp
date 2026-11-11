#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int dp[1005];
string dict[105]; 
int main() 
{
    string s;
    int n;
    cin >> s >> n;
    for (int i = 0; i < n; i++) 
    {
        cin >> dict[i];
    }
    int len = s.length();
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0; 
    for (int i = 0; i < len; i++) 
    {
        if (dp[i] == 0x3f3f3f3f) continue;

        for (int j = 0; j < n; j++) 
        {
            int lend = dict[j].size();
            if (i + lend <= len) 
            {
                if (s.substr(i, lend) == dict[j]) 
                {
                    dp[i + lend] = min(dp[i + lend], dp[i] + 1);
                }
            }
        }
    }
    cout << dp[len] << endl;
    return 0;
}
