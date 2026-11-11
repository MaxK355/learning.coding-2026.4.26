#include <iostream>
using namespace std;
int main()
{
    int prefix_sum[100005],a[100005];
    prefix_sum[0] = 0;
    int n,l,r,q;
    cin >> n;
    cin >> a[1];
    prefix_sum[1] = a[1];
    for(int i = 2;i <= n;i++)
    {
        cin >> a[i];
        prefix_sum[i] = prefix_sum[i - 1] + a[i];
    }
    cin >> q;
    for(int i = 0;i < q;i++)
    {
        cin >> l >> r;
        cout << prefix_sum[r] - prefix_sum[l - 1] << endl;
    }
    return 0;
}