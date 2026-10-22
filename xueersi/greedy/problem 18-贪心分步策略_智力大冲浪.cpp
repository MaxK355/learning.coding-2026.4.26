#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

struct node{
    int t,w;
}games[505];

bool cmp(node x,node y)
{
    return x.w > y.w;
}

bool vis[505];
int m,n;

int main(){
	cin >> m >> n;
	for(int i = 1;i <= n;i++)
	{
	    cin >> games[i].t;
	}
	for(int i = 1;i <= n;i++)
	{
	    cin >> games[i].w;
	}
	sort(games + 1, games + n + 1,cmp);
	for(int i = 1; i <= n;i++)
	{
	    bool flag = false;
	    for(int j = games[i].t; j >= 1;j--)
	    {
	        if(!vis[j])
	        {
	            vis[j] = true;
	            flag = true;
	            break;
	        }
	    }
	    if(!flag)
	    {
	        m -= games[i].w;
	    }
	}
	cout << m;
	return 0;
}