#include <iostream>
#include <algorithm>
using namespace std;

int n, m,a[100005],b[100005],a1[100005],b1[100005];

int main()
{
    cin >> n >> m;
    for(int i = 0;i < n;i++)
    {
        cin >> a[i];
        a1[i] = a[i];
    }
    for(int i = 0;i < m;i++)
    {
        cin >> b[i];
        b1[i] = b[i];
    }
    sort(a1,a1 + n);
    sort(b1,b1 + m);
    for(int i = 0;i < n;i++)
    {
        int count = upper_bound(b1,b1 + m, a[i]) - b1;
        cout << count << ' ';
    }
    cout << endl;
    for(int i = 0;i < m;i++)
    {
        int count = upper_bound(a1, a1 + n, b[i]) - a1;
        cout << count << ' ';
    }
    
}