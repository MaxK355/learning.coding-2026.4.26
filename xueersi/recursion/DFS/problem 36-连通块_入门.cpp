#include <iostream>
using namespace std;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int w, h, sx, sy, cnt;
char map_[25][25];
bool vis[25][25];
void dfs(int x, int y)
{
    for(int i = 0;i < 4;i++)
    {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx >= 0 && nx < h && ny >= 0 && ny < w)
        {
            if(map_[nx][ny] == '.' && !vis[nx][ny])
            {
                cnt++;
                vis[nx][ny] = 1;
                dfs(nx,ny);
            }
        }
    }
}
int main()
{
    cin >> w >> h;
    for(int i = 0;i < h; i++)
    {
        for(int j = 0;j < w;j++)
        {
            cin >> map_[i][j];
            if(map_[i][j] == '@')
            {
                sx = i;
                sy = j;
            }
        }
    }
    cnt++;
    vis[sx][sy] = 1;
    dfs(sx,sy);
    cout << cnt;
    return 0;
}