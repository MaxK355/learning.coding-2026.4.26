#include <iostream>
#include <cstring>
using namespace std;

int n, q, cnt, p[100000005];
bool f[100000005];

void EulerSieve(int n)
{
    memset(f, 1, sizeof(f));
    for(int i = 2;i <= n;i++)
    {
        if(f[i] == true)
        {
            p[++cnt] = i;
        }
        for(int j = 1;j <= cnt && i * p[j] <= n;j++)
        {
            f[i * p[j]] = 0;
            if(i % p[j] == 0)
            {
                break;
            }
        }
    }
}

int main()
{
    cin >> n >> q;
    EulerSieve(n);
    while(q--)
    {
        int k;
        cin >> k;
        cout << p[k] << endl;
    }
    return 0;
}