#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n, q;
    long long a[100005];
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a,a + n);
    while(q--)
    {
        long long k;
        cin >> k;

        long long l = 1, r = 2e18;

        while (l < r)
        {
            long long mid = l + (r - l) / 2;
            long long cnt = upper_bound(a, a + n, mid) - a;
            long long miss = mid - cnt;
            if (miss >= k)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        cout << l << endl;
    }

    return 0;
}