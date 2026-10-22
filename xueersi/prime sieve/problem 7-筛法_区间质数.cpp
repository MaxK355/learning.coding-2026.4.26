#include <iostream>
using namespace std;

bool ps[32000];
bool p[10000001];

void sv(int n)
{
    for(int i = 2; i <= n; i++)
    {
        ps[i] = true;
    }

    for(int i = 2; i * i <= n; i++)
    {
        if(ps[i])
        {
            for(int j = i * i; j <= n; j += i)
            {
                ps[j] = false;
            }
        }
    }
}

int main()
{
    int l, r, k;
    cin >> l >> r >> k;
    int lim = sqrt(r);
    sv(lim);
    for(int i = l; i <= r; i++)
    {
        p[i] = true;
    }
    for(int i = 2; i <= lim; i++)
    {
        if(ps[i])
        {
            long long st = max((long long)i * i,
                               (long long)((l + i - 1) / i) * i);

            for(long long j = st; j <= r; j += i)
            {
                p[j] = false;
            }
        }
    }
    p[0] = false;
    p[1] = false;
    int b = -1;
    for(int i = l; i <= r; i++)
    {
        if(p[i])
        {
            cout << i << " ";
            if(i <= k)
            {
                b = i;
            }
        }
    }
    cout << "\n" << b << "\n";
    return 0;
}