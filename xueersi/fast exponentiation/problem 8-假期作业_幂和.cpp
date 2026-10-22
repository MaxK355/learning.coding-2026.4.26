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
	LL ans;
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
	    ans += ksm(i,i,10007);
	}
	cout << ans % 10007;
	return 0;
}