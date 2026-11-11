#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n,m;
bool maze[55][55];
bool vis[55][55];
int sx,sy,fx,fy;
int dx[4] = {1,-1,0,0},dy[4] = {0,0,1,-1};
bool flag;

struct node{
    int x, y,step;
};

void bfs()
{
    queue<node> q;
    q.push({sx,sy,0});
    vis[sx][sy] = true;
    while(!q.empty())
    {
        node cur = q.front();
        q.pop();
        int cx = cur.x;
        int cy = cur.y;
        if(cx == fx && cy == fy)
        {
            cout << cur.step;
            return;
        }
        for(int i = 0;i < 4;i++)
        {
            int nx = cx + dx[i],ny = cy + dy[i];
            if(nx < n && ny < m && nx >= 0 && ny >= 0)
            {
                if(vis[nx][ny] == false)
                {
                    if(maze[nx][ny] == 1)
                    {
                        vis[nx][ny] = true;
                        int t = cur.step;
                        q.push({nx,ny, t + 1});
                    }
                }
            }
        }
    }
    cout << -1;
    return;
}

int main(){
	cin >> n >> m;
	string s;
	for(int i = 0;i < n;i++)
	{
	    cin >> s;
	    for(int j = 0;j < m;j++)
	    {
	        if(s[j] == '1')
	        {
	            maze[i][j] = 1;
	        }
	        else
	        {
	            maze[i][j] = 0;
	        }
	    }
	}
	cin >> sx >> sy >> fx >> fy;
	sx--;
	sy--;
	fx--;
	fy--;
	bfs();
	return 0;
}