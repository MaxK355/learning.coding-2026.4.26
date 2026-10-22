#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

struct node{
    long long x;
    int step;
};

int a,b,p,s;
bool vis[1000005];

int bfs()
{
    queue<node> q;
    q.push({a, 0});
    vis[a] = 1;
    while(!q.empty())
    {
        node cur = q.front();
        q.pop();
        if(cur.x == b)
        {
            return cur.step;
        }
        long long x1 = cur.x * p;
        if(x1 > b)
        {
        }
        else
        {
            if(!vis[x1])
            {
                q.push({x1,cur.step + 1});
                vis[x1] = 1;
            }
        }
        long long x2 = cur.x + s;
        if(x2 > b)
        {
        }
        else
        {
            if(!vis[x2])
            {
                q.push({x2,cur.step + 1});
                vis[x2] = 1;
            }
        }
    }
    return -1;
}

int main()
{
    cin >> a >> b >> p >> s;
    cout << bfs();
}