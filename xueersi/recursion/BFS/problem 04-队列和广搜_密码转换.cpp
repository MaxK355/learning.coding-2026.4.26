#include <iostream>
using namespace std;
int s,t,a[10000005],mod = 1;
bool vis[10000005];
struct node{
    int x,step;
};
void bfs()
{
    queue<node> q;
    vis[1] = 1;
    a[1] = 0;
    q.push({1, 0});
    while(!q.empty())
    {
        node cur = q.front();
        q.pop();
        int x = cur.x,y = cur.step;
        int next = (x%(mod/10)) * 10 + (x / (mod / 10));
        if(!vis[next])
        {
            vis[next] = 1;
            a[next] = y + 1;
            q.push({next,y + 1});
        }
        for(int i = 2;i <= t;i++)
        {
            next = (long long)x * i % mod;
            if(!vis[next])
            {
                vis[next] = 1;
                a[next] = y + 1;
                q.push({next,y + 1});
            }
        }
    }
}
int main()
{
    cin >> s >> t;
    for(int i = 0;i < s;i++)
    {
        mod *= 10;
    }
    bfs();
    int mx = -1,ans = 0;
    for(int i = 0;i < mod;i++)
    {
        if(vis[i] && a[i] > mx)
        {
            mx = a[i];
            ans = i;
        }
    }
    if(s == 2)
    {
        printf("%02d",ans);
    }
    if(s == 3)
    {
        printf("%03d",ans);
    }
    if(s == 4)
    {
        printf("%04d",ans);
    }
    if(s == 5)
    {
        printf("%05d",ans);
    }
    if(s == 6)
    {
        printf("%06d",ans);
    }
}