#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n,r,x[1005];

int main(){
	cin >> r >> n;
	for(int i = 1;i <= n;i++)
	{
	    cin >> x[i];
	}
	sort(x+1,x+n+1);
	int last = -1e9,cnt = 0;
	for(int i = 1;i <= n;i++)
	{
	    if(x[i] > last)
	    {
	        for(int j = 1;j <= n;j++)
	        {
	            if(x[j] - x[i] <= r)
	            {
	                last = x[j]+r;
	            }
	            else
	            {
	                break;
	            }
	        }
	        cnt++;
	    }
	}
	cout << cnt;
	return 0;
}