#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int n, a[15];
double ans = 1e9;
bool vis[15];
struct node{
    double x, y;
}d[15];
double len (int now,int last)
{
    return sqrt((d[last].x-d[now].x)*(d[last].x-d[now].x) + (d[last].y - d[now].y) * (d[last].y - d[now].y));
}
void dfs(int step,double sum)
{
    if(sum > ans)
    {
        return;
    }
    if(step > n)
    {
        ans = min(ans,sum);
        return;
    }
    for(int i = 1;i <= n;i++)
    {
        if(!vis[i])
        {
            a[step] = i;
            vis[i] = 1;
            dfs(step + 1,sum + len(i, a[step - 1]));
            vis[i] = 0;
        }
    }
}
int main()
{
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> d[i].x >> d[i].y;
    }
    d[0].x = 0;
    d[0].y = 0;
    dfs(1,0);
    printf("%.2lf",ans);
    return 0;
}