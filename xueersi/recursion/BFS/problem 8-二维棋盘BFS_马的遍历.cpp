#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n,m;
bool maze[405][405];
bool vis[405][405];
int sx,sy,fx,fy;
int dx[8] = {1,2,2,1,-1,-2,-2,-1},dy[8] = {2,1,-1,-2,-2,-1,1,2};
bool flag;
int dist[405][405];

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
        dist[cx][cy] = cur.step;
        for(int i = 0;i < 8;i++)
        {
            int nx = cx + dx[i],ny = cy + dy[i];
            if(nx < n && ny < m && nx >= 0 && ny >= 0)
            {
                if(vis[nx][ny] == false)
                {
                    vis[nx][ny] = true;
                    int t = cur.step;
                    q.push({nx,ny, t + 1});
                }
            }
        }
    }
    return;
}

int main(){
	cin >> n >> m;
	cin >> sx >> sy;
	sx--;
	sy--;
	for(int i = 0;i < n;i++)
	{
	    for(int j = 0;j < m;j++)
	    {
	        dist[i][j] = -1;
	    }
	}
	bfs();
	for(int i = 0;i < n;i++)
	{
	    for(int j = 0;j < m;j++)
	    {
	        printf("%-5d",dist[i][j]);
	    }
	    cout << endl;
	}
	return 0;
}