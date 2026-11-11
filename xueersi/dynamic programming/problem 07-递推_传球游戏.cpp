#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
long long a[35][35],m,n;
int main(){
	a[0][0] = 1;
	cin >> n >> m;
	for(int i = 1;i <= m;i++)
	{
	    for(int j = 0;j < n;j++)
	    {
	        if(j == 0)
	        {
	            a[i][j] = a[i - 1][n - 1] + a[i - 1][1];
	        }
	        else if(j == n - 1)
	        {
	            a[i][j] = a[i - 1][n - 2] + a[i - 1][0];
	        }
	        else
	        {
	            a[i][j] = a[i - 1][j - 1] + a[i - 1][j + 1];
	        }
	    }
	}
	cout << a[m][0] << endl;
	return 0;
}