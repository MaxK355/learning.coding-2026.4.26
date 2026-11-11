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
	LL n,mod = 1e9 + 7;
	cin >> n;
	if(n&1)
	{
	    cout << ksm(5, n/2 + 1,mod) * ksm(4,n/2,mod)% mod<< endl;
	}
	else
	{
	    cout << ksm(5, n/2,mod) * ksm(4,n/2,mod)% mod<< endl;
	}
	return 0;
}