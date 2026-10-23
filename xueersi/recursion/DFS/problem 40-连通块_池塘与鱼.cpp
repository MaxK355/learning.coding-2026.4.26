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
int n,m,q;
void dfs(int x,int y)
{
    for(int i = 0;i < 4;i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 1 && nx <= n && ny >= 1 && ny <= m)
        {
            if(map_[x][y] == map_[nx][ny] && !vis[nx][ny])
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
	    for(int j = 1;j <= m;j++)
	    {
	        cin >> map_[i][j];
	    }
	}
	for(int i = 1;i <= n;i++)
	{
	    for(int j = 1;j <= m;j++)
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
	cin >> q;
	while(q--)
	{
	    int x,y,x1,y1;
	    cin >> x >> y >> x1 >> y1;
	    if(vis[x][y] == vis[x1][y1])
	    {
	        cout << "Yes" << endl;
	    }
	    else
	    {
	        cout << "No";
	        cout << endl;
	    }
	}
	return 0;
}