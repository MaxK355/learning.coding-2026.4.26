#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

struct node{
    int p,a;
}milk[5005];

bool cmp(node x,node y)
{
    return x.p < y.p;
}

int n,m,ans=0;
int main(){
	cin >> n >>m;
	for(int i=1;i<=m;i++)
	{
	    cin >> milk[i].p >>milk[i].a;
	}
	sort(milk+1,milk+m+1,cmp);
	for(int i=0; i<=m;i++)
	{
	    if(n >= milk[i].a)
	    {
	        ans += milk[i].a * milk[i].p;
	        n -= milk[i].a;
	    }
	    else
	    {
	        ans += milk[i].p * n;
	        break;
	    }
	}
	cout << ans;
	return 0;
}