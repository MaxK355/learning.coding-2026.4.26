#include <iostream>
using namespace std;
int n, a[100005],ans[100005];
struct node {
    int x, step;
};
bool vis[100005];
void bfs()
{
    queue<node> q;
    q.push({0, 0});
    vis[0] = 1;
    while(!q.empty())
    {
        node cur = q.front();
        q.pop();
        int x1 = cur.x - 1;
        if(x1 >= 0 && x1 <= 100000 && !vis[x1])
        {
            q.push({x1,cur.step+1});
            ans[x1] = cur.step + 1;
            vis[x1] = 1;
        }
        int x2 = x1 + 2;
        if(x2 >= 0 && x2 <= 100000 && !vis[x2])
        {
            q.push({x2,cur.step+1});
            ans[x2] = cur.step + 1;
            vis[x2] = 1;
        }
        int x3 = a[cur.x];
        if(x3 >= 0 && x3 <= 100000 && !vis[x3])
        {
            q.push({x3,cur.step + 1});
            ans[x3] = cur.step + 1;
            vis[x3] = 1;
        }
    }
    return;
}

int main()
{
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    bfs();
    for(int i = 1;i <= n;i++)
    {
        cout << ans[i] << ' ';
    }
    return 0;
}