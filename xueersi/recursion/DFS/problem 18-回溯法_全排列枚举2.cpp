#include <iostream>
using namespace std;
int n, a[10],b[10];
bool vis[10];
void dfs(int step)
{
    if(step > n)
    {
        for(int i = 1;i <= n;i++)
        {
            cout << b[i] << ' ';
        }
        cout << endl;
        return;
    }
    for(int i = 1;i <= n;i++)
    {
        if(!vis[i])
        {
            b[step] = a[i];
            vis[i] = 1;
            dfs(step + 1);
            vis[i] = 0;
        }
    }
}
int main()
{
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    dfs(1);
    return 0;
}