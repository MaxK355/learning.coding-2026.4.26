#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int n,a[205],f[50];
struct node{
    int now,k,step;
};
bool vis[205][205];
int main()
{
    f[0] = 1;
    for(int i = 1;i <= 32;i++)
    {
        f[i] = f[i - 1] * 2;
    }
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    queue<node> q;
    q.push({1,0,0});
    vis[1][0] = 1;
    while(!q.empty())
    {
        node u = q.front();
        q.pop();
        if(u.now == n)
        {
            cout << u.step;
            return 0;
        }
        if(u.now > 1 && !vis[u.now - 1][u.k+1])
        {
            q.push({u.now - 1,u.k+1,u.step + 1});
            vis[u.now - 1][u.k + 1]= 1;
        }
        for(int i = u.now + 1;i <= n;i++)
        {
            if(a[u.now] + f[u.k] >= a[i] && !vis[i][0])
            {
                q.push({i,0,u.step+1});
                vis[i][0] = 1;
            }
        }
    }
    cout << -1;
    return 0;
}