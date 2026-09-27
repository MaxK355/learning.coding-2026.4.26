#include <iostream>
using namespace std;
int n, k, g[15][15], a[15],ans;
bool vis[15];
void dfs(int step)
{
    if(step > n)
    {
        ans++;
    }
    for(int i = 1;i <= n;i++)
    {
        if(vis[i])
        {
            continue;
        }
        if(g[i][a[step - 1]] == 1)
        {
            continue;
        }
        a[step] = i;
        vis[i] = 1;
        dfs(step + 1);
        vis[i] = 0;
    }
}
int main()
{
    cin >> n >> k;
    for(int i = 1;i <= k;i++)
    {
        int x,y;
        cin >> x >> y;
        g[x][y] = g[y][x] = 1;
    }
    dfs(1);
    cout << ans;
    return 0;
}