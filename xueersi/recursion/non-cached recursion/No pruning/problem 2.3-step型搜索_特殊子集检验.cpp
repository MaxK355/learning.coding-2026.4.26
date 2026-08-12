#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int t, n ,a[100],vis[100], ans[33000], cnt = 0;

void dfs(int step)
{
    if(step > n)
    {
        int sum = 0;
        for(int i = 1;i <= n;i++)
        {
            if(vis[i])
            {
                sum += a[i];
            }
        }
        ans[++cnt] = sum;
        return;
    }
    for(int i = 0;i <= 1;i++)
    {
        vis[step] = i;
        dfs(step + 1);
    }
}

int main(){
	cin >> t;
	while(t--)
	{
	    cin >> n;
	    for(int i = 1;i <= n;i++)
	    {
	        cin >> a[i];
	    }
	    cnt =0;
	    dfs(1);
	    sort(ans + 1,ans+cnt+1);
	    bool flag = true;
	    for(int i = 1;i <= cnt - 1;i++)
	    {
	        if(ans[i] == ans[i+1])
	        {
	            flag = false;
	        }
	    }
	    if(flag)
	    {
	        cout <<"Yes\n";
	    }
	    else
	    {
	        cout <<"No\n";
	    }
	}
	return 0;
}