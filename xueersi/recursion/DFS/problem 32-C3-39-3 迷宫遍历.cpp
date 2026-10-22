#include <iostream>
using namespace std;
int n, m;
char map67[25][25];
int ezx[4] = {-1,0,1,0}, ezy[4] = {0,1,0,-1};
int vis[25][25];
int pathx[500], pathy[500];
void dfs(int x, int y, int step)
{
    pathx[step] = x;
    pathy[step] = y;
    if(x == n && y == m)
    {
        for(int i = 0;i <= step;i++)
        {
            cout << '(' << pathx[i] << ',' << pathy[i] << ')' << ' ';
        }
        cout << endl;
        return;
    }
    for(int i = 0;i < 4;i++)
    {
        if(x + ezx[i] <= n && y + ezy[i] <= m && x + ezx[i] >= 1 && y + ezy[i] >= 1)
        {
            if(vis[x + ezx[i]][y + ezy[i]] == 0)
            {
                if(map67[x + ezx[i]][y + ezy[i]] == '.')
                {
                    vis[x + ezx[i]][y + ezy[i]]++;
                    dfs(x + ezx[i],y + ezy[i],step + 1);
                    vis[x + ezx[i]][y + ezy[i]]--;
                }
            }
        }
    }
    return;
}

int main()
{
    cin >> n >> m;
    vis[1][1] = 1;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            cin >> map67[i][j];
        }
    }
    dfs(1,1,0);
    return 0;
}