#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;

ll mem[1005][1005],mod = 1e9 + 7, n, k;

ll f(int n,int k)
{
    if(mem[n][k] != 0)
    {
        return mem[n][k];
    }
    else if(k > n || k == 0)
    {
        return mem[n][k] = 0;
    }
    else if(n == k)
    {
        return mem[n][k] = 1;
    }
    else if((1 < k || 1 == k))
    {
        return mem[n][k] = ((f(n - 1,k - 1) % mod) + ((k * f(n - 1,k)) % mod) % mod);
    }
}

int main()
{
    cin >> n >> k;
    cout << f(n, k) % mod;
}