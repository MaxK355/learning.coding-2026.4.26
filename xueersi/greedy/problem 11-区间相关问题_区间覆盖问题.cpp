#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

struct node{
    int start,end;
} a[200005];

bool cmp(node x, node y)
{
    return x.start < y.start;
}

int n,s,t;
int main(){
	cin >> n >> s >> t;
	for(int i = 1;i <= n;i++)
	{
	    cin >>a[i].start >>a[i].end;
	}
	sort(a+1,a+n+1,cmp);
	int id = 1,cnt = 0;
	while(id <= n && s < t && a[id].start <= s)
	{
	    int r = 0;
	    while(id <= n && a[id].start <= s)
	    {
	        r = max(r, a[id].end);
	        id++;
	    }
	    s = r;
	    cnt++;
	}
	if(s < t)
	{
	    cout << "impossible";
	}
	else
	{
	    cout << cnt;
	}
	return 0;
}