#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;
    long long first_element;
    cin >> first_element;
    long long dp0 = first_element;
    long long dp1 = -1e18; 
    long long max_ans = -1e18;
    long long max_val = first_element;
    long long second_max_val = LLONG_MIN;
    for (int i = 1; i < n; i++) 
    {
        long long cur;
        cin >> cur;
        if (cur > max_val) 
        {
            second_max_val = max_val;
            max_val = cur;
        } 
        else if (cur > second_max_val) 
        {
            second_max_val = cur;
        }
        long long last_dp0 = dp0;
        long long last_dp1 = dp1;
        dp0 = max(cur, last_dp0 + cur);
        dp1 = max(last_dp0, last_dp1 + cur);
        max_ans = max(max_ans, dp1);
    }
    if (max_val < 0) 
    {
        cout << max_val << endl;
    } 
    else 
    {
        cout << max_ans << endl;
    }
    return 0;
}
