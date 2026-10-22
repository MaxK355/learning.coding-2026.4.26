#include <iostream>
#include <algorithm>
using namespace std;

int n, a[300005], b[300005], mx, cnt;

int main()
{
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n;i++)
    {
        b[i] = a[i] + n - i + 1;
        mx = max(mx, b[i]);
    }
    for(int i = 1; i <= n;i++)
    {
        if(a[i] + n >= mx) 
        {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}