#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int n, m, t, sx, sy, fx, fy, obx, oby,cnt = 0;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
bool vis_map[10][10];

void dfs(int curx, int cury)
{
    if(curx == fx && cury == fy)
    {
        cnt++;
        return;
    }
    for(int i = 0;i < 4;i++)
    {
        int newx = curx + dx[i], newy = cury + dy[i];
        if(newx >= 1 && newx <= n && newy >= 1 && newy <= m)
        {
            if(!vis_map[newx][newy])
            {
                vis_map[newx][newy] = 1;
                dfs(newx, newy);
                vis_map[newx][newy] = 0;
            }
        }
    }
}

int main(){
	cin >> n >> m >> t;
	cin >> sx >> sy >> fx >> fy;
	for(int i = 0;i < t;i++)
	{
	    cin >> obx >> oby;
	    vis_map[obx][oby] = 1;
	}
	vis_map[sx][sy] = 1;
	dfs(sx, sy);
	cout << cnt;
	return 0;
}