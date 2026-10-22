#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int mul[3005], n, k;

void mult(int a[],int b,int c[])
{
    c[0] = a[0];
    int u = 0;
    for(int i = 1;i <= c[0];i++)
    {
        int t = a[i] * b + u;
        c[i] = t % 10;
        u = t / 10;
    }
    while(u > 0)
    {
        c[++c[0]] = u % 10;
        u /= 10;
    }
}

void print(int a[])
{
    for(int i = a[0];i >= 1;i--)
    {
        cout << a[i];
    }
}

void s2arr(string sa, int a[])
{
    a[0] = sa.size();
    for(int i = 1; i <= a[0];i++)
    {
        a[i] = sa[a[0]-i] - '0';
    }
}

int main(){
	cin >> n >> k;
	mul[0] = 1;
	mul[1] = 1;
	mult(mul, k, mul);
	for(int i = 2;i <= n;i++)
	{
	   mult(mul, k-1, mul);
	}
	print(mul);
	return 0;
}