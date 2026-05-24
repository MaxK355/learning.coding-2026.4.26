#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
struct node{
    double m, v, dv;
} a[105];

bool cmp(node x, node y)
{
    return x.dv > y.dv;
}

int main()
{
    int t, n;
    double ans = 0;
    cin >> n >> t;
    for(int i=1; i<= n; i++)
    {
        cin >> a[i].m >> a[i].v;
        a[i].dv = a[i].v / a[i].m;
    }
    sort(a+1, a+n+1, cmp);
    for(int i=1; i<=n;i++)
    {
        if(t >= a[i].m)
        {
            t -= a[i].m;
            ans += a[i].v;
        }
        else
        {
            ans += t * a[i].dv;
            break;
        }
    }
    printf("%.2lf", ans);
}