#include <iostream>
using namespace std;
long long rec(int n,int k)
{
    if((k == 0 && n != 0)|| k > n){
        return 0;
    }
    if(k == 0 && n == 0)
    {
        return 1;
    }
    return ( (long long)n * rec(n - 1, k - 1) + k * rec(n - 1,n - k) ) % 1000000007;
}
int main()
{
    int n ,k;
    cin >> n >> k;
    cout << rec(n,k);
}