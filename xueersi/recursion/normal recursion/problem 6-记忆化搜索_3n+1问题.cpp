#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

long long n, q;
const int maxn = 1e7;
int mem[10000005] = {};

long long f(long long n,long long len)
{
    long long start_n = n;
    if(start_n < maxn)
    {
        if(mem[n] != 0)
        {
            return mem[n];
        }
    }
    while(n != 1)
    {
        if(n % 2 != 0)
        {
            n = n * 3 + 1;
            len++;
            if(n < maxn)
            {
                if(mem[n] != 0)
                {
                    len = mem[n] + len - 1;
                    break;
                }
            }
        }
        else
        {
            n /= 2;
            len++;
            if(n < maxn)
            {
                if(mem[n] != 0)
                {
                    len = mem[n] + len - 1;
                    break;
                }
            }

        }
    }
    if(start_n < maxn) 
    {
        if(mem[start_n] == 0)
        {
            mem[start_n] = len;
        }
    }
    return len;
}

int main(){
    scanf("%lld",&q);
	for(int i = 0;i < q;i++)
	{
	    scanf("%lld",&n);
	    printf("%lld\n",f(n,1));
	}
	return 0;
}