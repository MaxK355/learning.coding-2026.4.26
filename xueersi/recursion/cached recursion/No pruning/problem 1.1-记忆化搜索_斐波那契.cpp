#include <iostream>
using namespace std;
typedef long long ll;
ll n, a[55] = {};

ll f(ll x)
{
    if(a[x] != 0)
    {
        return a[x];
    }
    a[x] = f(x - 1) + f(x - 2);
    return a[x];
}

int main()
{
    a[1] = 1;
    a[2] = 1;
    cin >> n;
    cout << f(n);
}
