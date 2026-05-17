#include <iostream>
#include <algorithm>
using namespace std;

long long daypoints[100005];
int k,m;
long long n,p,q;

int main()
{
    cin >> n >> m >> k;
    for(int i = 1;i <= k;i++)
    {
        cin >> p >> q;
        daypoints[p] += (n - q);
    }
    long long maxpoints = -1;
    for(int i = 1;i <= m;i++)
    {
        maxpoints = max(maxpoints, (long long)daypoints[i]);
    }
    cout << maxpoints;
    return 0;
}