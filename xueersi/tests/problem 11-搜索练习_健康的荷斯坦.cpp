#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int V,v[50],G,g[20][30],flag[30],minn = 1e9,ans[30];

void dfs(int step,int cnt)
{
    if(step > G)
    {
        int sum[30] = {};
        for(int i = 1;i <= G;i++)
        {
            if(flag[i])
            {
                for(int j = 1;j <= V;j++)
                {
                    sum[j] += g[i][j];
                }
            }
        }
        for(int i = 1;i <= V;i++)
        {
            if(v[i] > sum[i])
            {
                return;
            }
        }
        if(cnt < minn)
        {
            minn = cnt;
            for(int i = 1;i <= G;i++)
            {
                ans[i] = flag[i];
            }
        }
        return;
    }
    flag[step] = 1;
    dfs(step + 1,cnt + 1);
    flag[step] = 0;
    dfs(step + 1,cnt);
}

int main(){
	cin >> V;
	for(int i = 1;i <= V;i++)
	{
	    cin >> v[i];
	}
	cin >> G;
	for(int i = 1;i <= G;i++)
	{
	     for(int j = 1;j <= V;j++)
	     {
	         cin >> g[i][j];
	     }
	}
	dfs(1,0);
	cout << minn << ' ';
	for(int i = 0;i <= G;i++)
	{
	    if(ans[i])
	    {
	        cout << i << ' ';
	    }
	}
	return 0;
}