#include <iostream>
using namespace std;
int n, m;
char map67[25][25];
int ezx[4] = {-1,0,1,0}, ezy[4] = {0,1,0,-1};
int vis[25][25];
int cnt = 0;
int sx,sy,fx,fy;
void dfs(int x, int y, int step)
{
    if(x == fx && y == fy)
    {
        cnt++;
        return;
    }
    for(int i = 0;i < 4;i++)
    {
        if(x + ezx[i] <= n && y + ezy[i] <= m && x + ezx[i] >= 1 && y + ezy[i] >= 1)
        {
            if(vis[x + ezx[i]][y + ezy[i]] == 0)
            {
                vis[x + ezx[i]][y + ezy[i]]++;
                dfs(x + ezx[i],y + ezy[i],step + 1);
                vis[x + ezx[i]][y + ezy[i]]--;
            }
        }
    }
    return;
}

int main()
{
    cin >> n >> m;
    cin >> sx >> sy;
    cin >> fx >> fy;
    vis[sx][sy] = 1;
    dfs(sx,sy,0);
    cout << cnt;
    return 0;
}