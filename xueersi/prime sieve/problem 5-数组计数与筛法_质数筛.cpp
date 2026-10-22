#include <iostream>
#include <cstring>
using namespace std;

bool a[100005];
int n;

void primes(){
    memset(a, 1, sizeof(a));
    a[0] = 0;
    a[1] = 0;
    for(int i = 2;i * i <= 100005;i++)
    {
        if(a[i] == true)
        {
            for(int j = i * i;j <= 100005;j += i)
            {
                a[j] = 0;
            }
        }
    }
}

int main()
{
    cin >> n;
    primes();
    int p;
    for(int i = 0;i < n;i++)
    {
        cin >> p;
        if(a[p] == true)
        {
            cout << p << ' ';
        }
    }
}