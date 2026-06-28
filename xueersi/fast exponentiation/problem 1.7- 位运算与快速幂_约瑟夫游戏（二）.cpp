#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;

bool people[1005]={};

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
	LL n, m, k, ans = 0, elim,cur;
	cin >> n >> m >> k;
	for(int i = 2;i <= n;i++)
	{
	    elim = ksm(m, k + n - i + 1,i);
	    ans = (ans + elim) % i;
	}
	cout << ans + 1;
	return 0;
}