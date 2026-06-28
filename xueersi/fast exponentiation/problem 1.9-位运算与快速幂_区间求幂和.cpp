#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;

LL arr[2049];
LL prefix[100005];

LL ksm(LL a,LL b,LL p)
{
    LL ans = 1;
    if(b <= 1024)
    {
        return arr[b];
    }
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

LL precalculate(LL a,LL b,LL p)
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
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
	int n, a, q,b[100005];
	cin >> n >> a >> q;
	for(int i = 0;i <= 2048;i++)
	{
	    arr[i] = precalculate(a,i,1e9 + 7);
	}
	cin >> b[1];
	prefix[1] = b[1];
	for(int i = 2;i <= n;i++)
	{
	    cin >> b[i];
	    prefix[i] = prefix[i - 1] + b[i];
	}
	for (int i = 0; i < q; i++) 
	{
        int l, r;
        cin >> l >> r;
        LL ans,power = 0;
        power = prefix[r] - prefix[l - 1];
        cout << ksm(a, power, 1e9 + 7) << "\n";
    }
	return 0;
}