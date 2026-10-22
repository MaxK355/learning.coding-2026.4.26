#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int n,m;
char grass[105][105];
int sx1,sy1,sx2,sy2;
int dx[8] = {1,1,1,0,-1,-1,-1,0},dy[8] = {1,0,-1,-1,-1,0,1,1};
int dist[105][105];
bool vis[105][105];

struct node{
    int x, y,step;
};

void bfs(int sx,int sy)
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
            if(nx < n && nx >= 0 && ny < m && ny >= 0)
            {
                if(vis[nx][ny] == false && grass[nx][ny] != '*')
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
	cin >> sx1 >> sy1;
	sx1--;
	sy1--;
	string s;
	for(int i = 0;i < n;i++)
	{
	    cin >> s;
	    for(int j = 0;j < m;j++)
	    {
	        grass[i][j] = s[j];
	    }
	}
	bfs(sx1,sy1);
	int maxn = 0;
	for(int i = 0;i < n;i++)
	{
	    for(int j = 0;j < m;j++)
	    {
	        if(dist[i][j] > maxn)
	        {
	            maxn = dist[i][j];
	        }
	    }
	}
	cout << maxn;
	return 0;
}