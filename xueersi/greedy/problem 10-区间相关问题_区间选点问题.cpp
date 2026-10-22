#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

struct node{
    int start, end;
} a[200005];

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
	int pos = -1e9,cnt = 0;
	for(int i = 1;i <= n;i++)
	{
	    if(pos < a[i].start)
	    {
	        cnt++;
	        pos = a[i].end;
	    }
	}
	cout << cnt;
	return 0;
}