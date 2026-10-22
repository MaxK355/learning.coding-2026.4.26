#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

struct node{
    int start,end;
} a[1005];

bool cmp(node x,node y)
{
    return x.end < y.end;
}

int n;

int main(){
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
	    cin >> a[i].start >> a[i].end;
	}
	sort(a+1,a+n+1,cmp);
	int t = 0,cnt = 0;
	for(int i = 1;i <= n;i++)
	{
	    if(t <= a[i].start)
	    {
	        t = a[i].end;
	        cnt++;
	    }
	}
	cout << cnt;
	return 0;
}