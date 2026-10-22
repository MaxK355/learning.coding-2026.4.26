#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
    long long start, end;
} a[200];

bool cmp(node x, node y)
{
    return x.end < y.end;
}

int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i].start >> a[i].end;

    sort(a, a + n, cmp);

    long long t1 = 0, t2 = 0;
    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        if(a[i].start >= t1 && a[i].start >= t2)
        {
            if(t1 > t2)
            {
                t1 = a[i].end;
            }
            else
            {
                t2 = a[i].end;
            }
            ans++;
        }
        else if(a[i].start >= t1)
        {
            t1 = a[i].end;
            ans++;
        }
        else if(a[i].start >= t2)
        {
            t2 = a[i].end;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}