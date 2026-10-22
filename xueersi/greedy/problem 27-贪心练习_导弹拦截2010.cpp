#include <iostream>
#include <algorithm>
using namespace std;

struct node{
    int d1,d2;
}a[100005];

bool cmp(node x, node y)
{
    return x.d1 < y.d1;
}

int main()
{
    int x1,y1,x2,y2,n;
    cin >> x1 >> y1 >> x2 >> y2 >> n;
    for(int i = 1;i <= n;i++)
    {
        int x,y;
        cin >> x >> y;
        a[i].d1 = (x1 - x) * (x1 - x) + (y1 - y) * (y1 - y);
        a[i].d2 = (x2 - x) * (x2 - x) + (y2 - y) * (y2 - y);
    }
    sort(a + 1,a + n + 1, cmp);
    int r2_2 = 0, mn = 2e9;
    for(int i = n;i >= 0;i--)
    {
        mn = min(mn, a[i].d1 + r2_2);
        r2_2 = max(r2_2, a[i].d2);
    }
    cout << mn;
    return 0;
}