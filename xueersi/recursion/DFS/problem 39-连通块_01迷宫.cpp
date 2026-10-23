#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
char map_[1005][1005];
int vis[1005][1005];
int ans[1000005];
int flag;
int n,m;
void dfs(int x,int y)
{
    for(int i = 0;i < 4;i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 1 && nx <= n && ny >= 1 && ny <= n)
        {
            if(map_[x][y] != map_[nx][ny] && !vis[nx][ny])
            {
                vis[nx][ny] = flag;
                ans[flag]++;
                dfs(nx,ny);
            }
            
        }
    }
}

int main()
{
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
	    for(int j = 1;j <= n;j++)
	    {
	        cin >> map_[i][j];
	    }
	}
	for(int i = 1;i <= n;i++)
	{
	    for(int j = 1;j <= n;j++)
	    {
	        if(!vis[i][j])
	        {
	            flag++;
	            vis[i][j] = flag;
	            ans[flag]++;
	            dfs(i,j);
	        }
	    }
	}
	while(m--)
	{
	    int x,y;
	    cin >> x >> y;
	    cout<< ans[vis[x][y]]<<endl;
	}
	return 0;
}