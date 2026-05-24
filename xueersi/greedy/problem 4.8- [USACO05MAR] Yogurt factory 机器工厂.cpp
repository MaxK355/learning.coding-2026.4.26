#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, s;
    cin >> n >> s;
    long long cnt = 0;
    int min_cost = 1e9;
    for (int i = 1; i <= n; i++) 
    {
        int c, y;
        cin >> c >> y;
        if (i == 1) 
        {
            min_cost = c;
        } 
        else 
        {
            min_cost = min(min_cost + s, c);
        }
        cnt += (long long)min_cost * y;
    }
    cout << cnt;
    return 0;
}