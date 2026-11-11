#include <iostream>
using namespace std;
using ll = long long;
ll recur(ll n,ll x)
{
    if(n == 0)
    {
        return 1;
    }
    else if(n == 1)
    {
        return 2 * x;
    }
    else
    {
        return (2 * x * recur(n - 1,x)) - (2 * (n - 1) * recur(n - 2,x));
    }
}
int main()
{
    int x,n;
    cin >> n >> x;
    cout << recur(n, x);
}