#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

struct node{
    int start,end;
} a[10005];

bool cmp(node x,node y)
{
    return x.end < y.end;
}

int n,t;

int main(){
	cin >> n;
	
	for(int i = 1;i <= n;i++)
	{
	    cin >> a[i].start >> t;
	    a[i].end = a[i].start + t;
	}
	sort(a+1,a+n+1,cmp);
	int now = 0,cnt = 0;
	for(int i = 1;i <= n;i++)
	{
	    if(now <= a[i].start)
	    {
	        now = a[i].end;
	        cnt++;
	    }
	}
	cout << cnt;
	return 0;
}