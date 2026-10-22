#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int n;
struct node{
    int num;
    int step;
};
bool vis[200005];
int bfs()
{
    queue<node> q;
    q.push({1,0});
    while(!q.empty())
    {
        node cur = q.front();
        q.pop();
        if(cur.num % n == 0)
        {
            return cur.step;
        }
        int x1 = (cur.num * 10) % n;
        if(!vis[x1])
        {
            q.push({x1,cur.step + 1});
            vis[x1] = 1;
        }
        int x2 = (cur.num * 10 + 1) % n;
        if(!vis[x2])
        {
            q.push({x2,cur.step + 1});
            vis[x2] = 1;
        }
    }
    return -1;
}
int main()
{
    cin >> n;
    cout << bfs();
    return 0;
}