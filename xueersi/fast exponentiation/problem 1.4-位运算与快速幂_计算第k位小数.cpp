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
	LL T, a, b, k;
	cin >> T;
	while(T--)
	{
	    cin >> a >> b >> k;
	    cout << a % b * ksm(10, k-1, b) % b * 10 / b << endl;
	}
	return 0;
}