#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int n,b,h[100], ans = 2e9;
bool vis[100];

void dfs(int step)
{
    if(step > n)
    {
        int sum = 0;
        for(int i = 1;i <= n;i++)
        {
            if(vis[i])
            {
                sum += h[i];
            }
            if(sum >= b)
            {
                ans = min(ans,sum - b);
                return;
            }
        }
        return;
    }
    for(int i = 1;i >= 0;i--)
    {
        vis[step] = i;
        dfs(step + 1);
    }
}

int main(){
    cin >> n >> b;
    for(int i = 1;i <= n;i++)
    {
        cin >>  h[i];
    }
    dfs(1);
    cout << ans;
	return 0;
}