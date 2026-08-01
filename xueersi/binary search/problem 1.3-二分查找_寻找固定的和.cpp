#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int n, k;
int x[200005], y[200005];
bool y_use[200005];

int main(){
    int cnt = 0;
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
	{
	    cin >> x[i];
	}
	for(int i = 1;i <= n;i++)
	{
	    cin >> y[i];
	    y[i] = k - y[i];
	}
	sort(y + 1,y + n + 1);
	sort(x + 1,x + n + 1);
	int L = 1;
	for(int i = 1;i <= n;i++)
	{
	    int p = lower_bound(x + L, x + n + 1, y[i]) - x;
	    if(y[i] == x[p])
	    {
	        cnt++;
	        L = p + 1;
	    }
	}
	cout << cnt;
	return 0;
}