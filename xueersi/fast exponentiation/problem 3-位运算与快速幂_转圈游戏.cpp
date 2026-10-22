#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;

LL ksm(LL a,LL b,LL p)
{
    LL ans = 1;
    while(b){
        if(b&1) 
        {
            ans = ans * a % p;
        }
            a = a * a % p;
            b = b >> 1;
    }
    return ans % p;
}

int main(){
    LL n,m,k,x;
    cin >> n >> m >> k >> x;
    cout <<(x + ksm(10, k, n) * m) % n;
	return 0;
}