#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int n,q;
long long a[100005],d;

int main(){
	cin >> n >> q;
	for(int i = 1;i <= n;i++)
	{
	    cin >> a[i];
	    a[i] -= i;
	}
	sort(a + 1, a + n + 1);
	while(q--)
	{
	    cin >> d;
	    int p = lower_bound(a + 1, a + n + 1, d) - a;
	    if(a[p] == d)
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