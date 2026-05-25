#include <iostream>
using namespace std;
bool isPrime[11000001];
int primes[700005];
void prime(int mx) 
{
    for (int i = 0; i <= 11000000; i++) 
    {
        isPrime[i] = true;
    }
    isPrime[0] = isPrime[1] = false;
    int cnt = 0;
    for(int i = 2; i <= 11000000; i++) 
    {
        if(isPrime[i]) 
        {

            primes[cnt++] = i;

            if(cnt >= mx) 
            {
                return;
            }

            if((long long)i * i <= 11000000) 
            {

                for(int j = i * i; j <= 11000000; j += i) 
                {
                    isPrime[j] = false;
                }
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    int query[100005];
    int mx = 0;
    for(int i = 0; i < n; i++) 
    {
        cin >> query[i];
        mx = max(mx, query[i]);
    }
    prime(mx);
    for(int i = 0; i < n; i++) 
    {
        cout << primes[query[i] - 1] << '\n';
    }
    return 0;
}