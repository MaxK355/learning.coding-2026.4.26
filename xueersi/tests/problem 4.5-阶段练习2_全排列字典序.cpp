#include <iostream>
using namespace std;

int n;
int P[10], Q[10], a[10];

bool same(int x[], int y[])
{
    for (int i = 0; i < n; i++)
    {
        if (x[i] != y[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> P[i];
    }
    for (int i = 0; i < n; i++) 
    {
        cin >> Q[i];
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;
    }
    int cnt = 1;
    int posP = 0, posQ = 0;
    do
    {
        if (same(a, P)) posP = cnt;
        if (same(a, Q)) posQ = cnt;
        cnt++;
    }
    while(next_permutation(a, a + n));

    cout << abs(posP - posQ);

    return 0;
}