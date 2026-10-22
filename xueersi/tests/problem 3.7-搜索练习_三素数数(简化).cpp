#include <iostream>
using namespace std;
int n, cnt = 0,a[20];
bool vis[1005];
void dfs(int step)
{
    if(step == n)
    {
        cnt++;
        return;
    }
    if(step == 0 || step == 1)
    {
        for(int i = 1;i < 10;i++)
        {
            a[step] = i;
            dfs(step + 1);
        }
    }
    else
    {
        for(int i = 1;i < 10;i += 2)
        {
            int calc = 0;
            a[step] = i;
            calc += a[step - 2];
            calc *= 10;
            calc += a[step - 1];
            calc *= 10;
            calc += a[step];
            if(!vis[calc])
            {
                dfs(step + 1);
            }
        }
    }
}
int main()
{
    cin >> n;
    for(int i = 2;i <= 999;i++)
    {
        if(vis[i] == 0)
        {
            for(int j = 2 * i;j <= 999;j += i)
            {
                vis[j] = 1;
            }
        }
    }
    dfs(0);
    cout << cnt;
}