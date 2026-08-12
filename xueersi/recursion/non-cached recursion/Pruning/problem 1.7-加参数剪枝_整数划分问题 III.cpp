#include <iostream>
using namespace std;
int n,k,a[25];
bool vis[25];

void dfs(int step, int sum)
{
    if(sum > n)
    {
        return;
    }
    if(step > k)
    {
        if(sum == n)
        {
            for(int i = 1;i <= k;i++)
            {
                if(vis[i])
                {
                    cout << a[i] << ' ';
                }
            }
            cout << endl;
        }
        return;
    }
    for(int i = 1;i >= 0;i--)
    {
        vis[step] = i;
        dfs(step + 1,sum + a[step] * i);
    }
}

int main()
{
    cin >> n >> k;
    for(int i = 1;i <= k;i++)
    {
        cin >> a[i];
    }
    dfs(1,0);
    return 0;
}