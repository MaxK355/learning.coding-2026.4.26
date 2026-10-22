#include <iostream>
#include <algorithm>
using namespace std;

int n,k,a[200005],mx = -1;

int main() {
	cin >> k >> n;
	for(int i = 1;i <= n;i++)
	{
	    cin >> a[i];
	}
	for(int i = 1;i <= n;i++)
	{
	    if(i == n)
	    {
	        mx = max(mx, k - (abs(a[n] - a[1])));
	        break;
	    }
	    mx = max(mx, min(a[i+1] - a[i],k - (abs(a[i] - a[i+1]))));
	}
	cout << k - mx;
    return 0;
}