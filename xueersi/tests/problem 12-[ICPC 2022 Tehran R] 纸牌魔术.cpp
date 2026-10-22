#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int n,a,b;
struct node{
    int x,step;
};
bool vis[200005];
int bfs()
{
    queue<node> q;
    q.push({a,0});
    vis[a] = 1;
    while(!q.empty())
    {
        node cur = q.front();
        q.pop();
        if(cur.x == b)
        {
            return cur.step;
        }
        int x1,x2;
        if(cur.x <= n)
        {
            x1 = 2 * cur.x - 1;
        }
        else
        {
            x1 = 2 * cur.x - 2*n;
        }
        if(!vis[x1])
        {
            q.push({x1,cur.step + 1});
            vis[x1] = 1;
        }
        if(cur.x % 2 == 0)
        {
            x2 = cur.x - 1;
        }
        else
        {
            x2 = cur.x + 1;
        }
        if(!vis[x2])
        {
            q.push({x2,cur.step + 1});
            vis[x2] = 1;
        }
    }
}
int main()
{
    cin >> n >> a >> b;
    cout << bfs();
    return 0;
}