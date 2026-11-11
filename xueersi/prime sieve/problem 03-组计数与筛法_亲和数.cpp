#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int m, f[2000005], sum = 0;

void primes(int n){
    f[1] = 0;
    for(int i = 2;i <= n;i++)
    {
        f[i] += 1;
        for(int j = 2;j * i <= n;j++)
        {
            f[i * j] += i;
        }
    }
}

int main(){
	cin >> m;
	primes(m);
	for(int i = 1; i < m;i++)
	{
	    int b = f[i];
	    if(i < b && b < m && f[b] == i)
	    {
	        sum += i + b;
	    }
	}
	cout << sum;
	return 0;
}