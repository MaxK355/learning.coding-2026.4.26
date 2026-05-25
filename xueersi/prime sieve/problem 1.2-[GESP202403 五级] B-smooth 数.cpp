#include <iostream>
using namespace std;

int n, b, f[1000005], cnt = 0;

void primes(int n)
{
    f[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        if(!f[i])
        {
            for(int j = 1; i * j <= n; j++)
            {
                f[i * j] = i;
            }
        }
    }
}

int main()
{
    cin >> n >> b;
    primes(n);
    for(int i = 1; i <= n; i++)
    {
        if(f[i] <= b)
        {
            cnt++;
        }
    }
    cout << cnt;
}