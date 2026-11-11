#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
long long a[45] = {},b[45] = {},c[45] = {},d[45] = {};
int n;
int main(){
	cin >> n;
	a[0] = 1;
	for(int i = 1;i < n;i++)
	{
	    a[i] = b[i - 1] + c[i - 1] + d[i - 1];
	    b[i] = a[i - 1] + c[i - 1] + d[i - 1];
	    c[i] = b[i - 1] + a[i - 1] + d[i - 1];
	    d[i] = b[i - 1] + c[i - 1] + a[i - 1];
	}
	cout << b[n - 1] + c[n - 1] + d[n - 1] << endl;
	return 0;
}