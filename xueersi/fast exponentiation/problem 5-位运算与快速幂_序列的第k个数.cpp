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
	LL T, a, b, c,k,mod = 200907;
	cin >> T;
	while(T--)
	{
	    cin >> a >> b >> c >> k;
	    if(b - a == c - b)
	    {
	        cout << (a + (k - 1) * (b - a)) % mod << endl;
	    }
	    else
	    {
	        cout << a * ksm(b / a,k - 1, mod)% mod << endl;
	    }
	}
	return 0;
}