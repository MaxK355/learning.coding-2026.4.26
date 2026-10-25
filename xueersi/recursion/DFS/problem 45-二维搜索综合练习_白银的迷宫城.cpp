#include <iostream>
#include <algorithm>
using namespace std;
char map_[1005][1005];
int vis[1005][1005];
int ans[1000005];
int n, m, flag;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
void dfs(int x, int y) 
{
    for (int i = 0;i < 4;i++) 
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m) 
        {
            if (map_[nx][ny] == '.' && !vis[nx][ny]) 
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
            if (map_[i][j] == '.' && !vis[i][j])
            {
                flag++;
                vis[i][j] = flag;
                ans[flag]++;
                dfs(i, j);
            }
        }
    }
    for(int i = 1; i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            if(map_[i][j] == '*')
            {
                int b[4] = {};
                for(int k = 0;k <= 3;k++)
                {
                    int ni = i + dx[k], nj = j + dy[k];
                    b[k] = vis[ni][nj];
                }
                sort(b + 0,b + 3 + 1);
                int sum = 1 + ans[b[0]];
                if(b[1] != b[0])
                {
                    sum += ans[b[1]];
                }
                if(b[2] != b[1])
                {
                    sum += ans[b[2]];
                }
                if(b[3] != b[2])
                {
                    sum += ans[b[3]];
                }
                map_[i][j] = sum % 10 + '0';
            }
        }
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            cout << map_[i][j];
        }
        cout << endl;
    }
    return 0;
}
