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
	LL m, n;
	cin >> m >> n;
	LL s1 = ksm(m, n, 100003);
	LL s2 = m * ksm(m - 1,n - 1,100003) % 100003;
	if((s1 - s2) < 0)
	{
	    cout << s1 - s2 + 100003;
	}
	else
	{
	    cout << s1 - s2;
	}
	return 0;
}