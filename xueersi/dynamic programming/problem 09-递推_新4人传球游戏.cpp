#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
long long n,a[45],b[45],c[45],d[45];
int main()
{
	cin >> n;
	a[1] = 0;
	b[1] = 1;
	c[1] = 1;
	d[1] = 1;
	for(int i = 2;i <=n ;i++)
	{
	    a[i] = c[i - 1] + d[i - 1];
	    b[i] = a[i - 1] + c[i - 1] + d[i - 1];
	    c[i] = a[i - 1] + b[i - 1] + d[i - 1];
	    d[i] = a[i - 1] + c[i - 1] + b[i - 1];
	}
	cout << a[n];
	return 0;
}