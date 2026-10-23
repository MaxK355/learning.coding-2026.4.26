#include <iostream>
using namespace std;
int n, m;
char map_[105][105];
bool vis[105][105];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
void dfs(int x, int y) {
    vis[x][y] = true;

    for (int i = 0; i < 4; i++) 
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m) 
        {
            if (map_[nx][ny] == '.' && !vis[nx][ny]) 
            {
                if (map_[x][y] == 'B') 
                {
                    map_[nx][ny] = 'W';
                } 
                else 
                {
                    map_[nx][ny] = 'B';
                }
                
                dfs(nx, ny);
            }
        }
    }
}

int main() 
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) 
        {
            cin >> map_[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) 
        {
            if (map_[i][j] == '.' && !vis[i][j]) 
            {
                map_[i][j] = 'B'; 
                dfs(i, j);
            }
        }
    }
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < m; ++j) 
        {
            cout << map_[i][j];
        }
        cout << endl;
    }
    return 0;
}
