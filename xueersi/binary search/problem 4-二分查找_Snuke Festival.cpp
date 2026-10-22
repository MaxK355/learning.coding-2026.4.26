#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;
int n;
int a[200200];
int b[200200];
int c[200200];
long long total = 0;
int main()
{
    cin >> n;
    for(int i = 0;i < n;i++) cin >> a[i];
    for(int i = 0;i < n;i++) cin >> b[i];
    for(int i = 0;i < n;i++) cin >> c[i];
    sort(a,a + n);
    sort(c,c + n);
    for(int i = 0;i < n;i++)
    {
        int a1 = lower_bound(a, a + n, b[i]) - a;
        int c1 = upper_bound(c, c + n, b[i]) - c;
        long long count = n - c1;
        total += (long long)(a1) * count;
    }
    cout << total;
}
