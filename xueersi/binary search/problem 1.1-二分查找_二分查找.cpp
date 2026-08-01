#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int n, q;
long long a[100005], b[100005];

int main(){
	cin >> n >> q;
	for(int i = 0;i < n;i++)
	{
	    cin >> a[i];
	}
	for(int i = 0;i < q;i++)
	{
	    cin >> b[i];
	}
	sort(a,a+n);
	for(int i = 0;i < q;i++)
	{
	    if(binary_search(a,a + n,b[i]) == true)
	    {
	        cout << "Yes" << endl;
	    }
	    else
	    {
	        cout << "No" << endl;
	    }
	}
	return 0;
}