#include <iostream>
#include <algorithm>
using namespace std;

struct node{
    int p,amt;
} a[105];

bool cmp(node x, node y)
{
    return x.p < y.p;
}

int main()
{
    int m,n,cnt = 0;
    cin >> m >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i].p >> a[i].amt;
    }
    sort(a+1, a+n+1, cmp);
    for(int i=1;i<=n;i++)
    {
        if(m >= a[i].p * a[i].amt)
        {
            m -= a[i].p * a[i].amt;
            cnt += a[i].amt;
        }
        else
        {
            cnt += m / a[i].p;
            break;
        }
    }
    cout << cnt;
}