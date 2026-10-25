#include <iostream>
using namespace std;
int map_[1005][1005];
int vis[1005][1005];
int ans[1000005];
int sum[1000005];
int n, t, flag;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
void dfs(int x, int y) 
{
    for (int i = 0;i < 4;i++) 
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= n) 
        {
            if (map_[nx][ny] > 0 && !vis[nx][ny]) 
            {
                vis[nx][ny] = flag;
                ans[flag]++;
                sum[flag] += map_[nx][ny];
                dfs(nx, ny);
            }
        }
    }
}

int main() {
    cin >> n >> t;
    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= n; j++) 
        {
            cin >> map_[i][j];
        }
    }
    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= n; j++) 
        {
            if (map_[i][j] > 0 && !vis[i][j])
            {
                flag++;
                vis[i][j] = flag;
                ans[flag]++;
                sum[flag] += map_[i][j];
                dfs(i, j);
            }
        }
    }
    for (int i = 0; i < t; i++)
    {
        int x, j;
        cin >> x >> j;
        if (vis[x][j] == 0) 
        {
            cout << -1 << endl;
        } 
        else 
        {
            cout << ans[vis[x][j]] << " " << sum[vis[x][j]] << endl;
        }
    }
    return 0;
}
