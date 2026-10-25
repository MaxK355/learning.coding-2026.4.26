#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
char map_[1005][1005];
int vis[1005][1005];
int ans[1000005];
int n, m, flag;
int dx[] = {1,1,1,0,0,-1,-1,-1};
int dy[] = {1,0,-1,1,-1,1,0,-1};
void dfs(int x, int y) 
{
    for (int i = 0;i < 8;i++) 
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m) 
        {
            if (map_[nx][ny] == '*' && !vis[nx][ny]) 
            {
                vis[nx][ny] = flag;
                ans[flag]++;
                dfs(nx, ny);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= m; j++) 
        {
            cin >> map_[i][j];
        }
    }
    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= m; j++) 
        {
            if (map_[i][j] == '*' && !vis[i][j])
            {
                flag++;
                vis[i][j] = flag;
                ans[flag]++;
                dfs(i, j);
            }
        }
    }
    int maxcnt = 0;
    for(int i = 1; i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            if(map_[i][j] == '.')
            {
                set<int> a;
                int cnt = 0;
                for (int k = 0;k < 8;k++) 
                {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx >= 1 && nx <= n && ny >= 1 && ny <= m) 
                    {
                        if(map_[nx][ny] == '*') 
                        {
                            if(a.count(vis[nx][ny]) == 0)
                            {
                                a.insert(vis[nx][ny]);
                                cnt++;
                            }
                        }
                    }
                }
                maxcnt = max(maxcnt, cnt);
            }
        }
    }
    if(maxcnt == 0)
    {
        cout << flag;
    }
    else
    {
        cout << flag - maxcnt + 1;
    }
    return 0;
}
