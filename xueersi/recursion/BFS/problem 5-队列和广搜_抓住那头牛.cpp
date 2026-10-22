#include <iostream>
using namespace std;
int n, k;
struct node {
    int x, step;
};
bool vis[100005];
int bfs()
{
    queue<node> q;
    q.push({n, 0});
    vis[n] = 1;
    while(!q.empty())
    {
        node cur = q.front();
        q.pop();
        if(cur.x == k)
        {
            return cur.step;
        }
        int x1 = cur.x - 1;
        if(x1 >= 0 && x1 <= 100000 && !vis[x1])
        {
            q.push({x1,cur.step+1});
            vis[x1] = 1;
        }
        int x2 = x1 + 2;
        if(x2 >= 0 && x2 <= 100000 && !vis[x2])
        {
            q.push({x2,cur.step+1});
            vis[x2] = 1;
        }
        int x3 = 2 * cur.x;
        if(x3 >= 0 && x3 <= 100000 && !vis[x3])
        {
            q.push({x3,cur.step + 1});
            vis[x3] = 1;
        }
    }
}

int main()
{
    cin >> n >> k;
    cout << bfs();
    return 0;
}