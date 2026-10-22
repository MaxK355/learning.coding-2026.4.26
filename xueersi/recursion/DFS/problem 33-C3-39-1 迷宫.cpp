#include <iostream>
using namespace std;
int n, m;
char map67[25][25];
int ezx[4] = {1,-1,0,0}, ezy[4] = {0,0,-1,1};
int vis[25][25];
bool flaggggg;
void dfs(int x, int y)
{
    if(x == n - 1 && y == m - 1)
    {
        flaggggg = true;
        return;
    }
    if(flaggggg == true)
    {
        return;
    }
    for(int i = 0;i < 4;i++)
    {
        if(x + ezx[i] < n && y + ezy[i] < m && x + ezx[i] >= 0 && y + ezy[i] >= 0)
        {
            if(vis[x + ezx[i]][y + ezy[i]] == 0)
            {
                if(map67[x + ezx[i]][y + ezy[i]] == '.')
                {
                    vis[x + ezx[i]][y + ezy[i]]++;
                    dfs(x + ezx[i],y + ezy[i]);
                    vis[x + ezx[i]][y + ezy[i]]++;
                }
            }
        }
    }
    return;
}

int main()
{
    cin >> n >> m;
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++)
        {
            cin >> map67[i][j];
        }
    }
    dfs(0,0);
    if(flaggggg == true)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}