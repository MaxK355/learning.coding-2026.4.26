#include <iostream>
#include <algorithm>
using namespace std;
int a[305], n;
long long cnt = 0;
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    
    int l = 1, r = n;
    
    cnt = a[r] * a[r];
    int last = a[r];
    r--;
    
    for(int i = 2; i <= n; i++)
    {
        int now;
        if(i % 2 == 0) 
        {
            now = a[l];
            l++;
        }
        else 
        {
            now = a[r];
            r--;
        }
        cnt += (last - now) * (last - now);
        last = now;
    }
    
    cout << cnt;
    return 0;
}
