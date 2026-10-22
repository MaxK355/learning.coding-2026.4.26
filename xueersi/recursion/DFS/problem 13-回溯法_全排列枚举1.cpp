#include <iostream>
using namespace std;
int n, a[10];
bool vis[10];
void dfs(int step)
{
    if(step > n)
    {
        for(int i = 1;i <= n;i++)
        {
            cout << a[i] << ' ';
        }
        cout << endl;
        return;
    }
    for(int i = 1;i <= n;i++)
    {
        if(!vis[i])
        {
            a[step] = i;
            vis[i] = 1;
            dfs(step + 1);
            vis[i] = 0;
        }
    }
}
int main()
{
    cin >> n;
    dfs(1);
    return 0;
}