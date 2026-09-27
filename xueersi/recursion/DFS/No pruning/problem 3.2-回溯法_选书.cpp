#include <iostream>
using namespace std;
int n, a[25], g[25][25],ans;
bool vis[25];
void dfs(int step)
{
    if(step > n)
    {
        ans++;
        return;
    }
    for(int i;i <= n;i++)
    {
        if(vis[i])
        {
            continue;
        }
        if(g[step][i] == 0)
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
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        int x,y;
        cin >> x >> y;
        g[i][x] = g[i][y] = 1;
    }
    dfs(1);
    cout << ans;
}