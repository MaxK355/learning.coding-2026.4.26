#include <iostream>
using namespace std;

long long m;
int a[100005],n;

int main()
{
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    int cnt = 1;
    long long num = 0;
    for(int i = 1;i <= n;i++)
    {
        if(num + a[i] <= m)
        {
            num += a[i];
        }
        else
        {
            cnt++;
            num = a[i];
        }
    }
    cout << cnt;
    return 0;
}