#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n,m;
bool vis[25][25];
int sx1,sy1,sx2,sy2;
int dx[12] = {1,2,2,1,-1,-2,-2,-1,2,2,-2,-2},dy[12] = {2,1,-1,-2,-2,-1,1,2,2,-2,-2,2};

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
        if(cx == 0 && cy == 0)
        {
            cout << cur.step;
            return;
        }
        for(int i = 0;i < 12;i++)
        {
            int nx = cx + dx[i],ny = cy + dy[i];
            if(nx <= 20 && nx >= 0 && ny <= 20 && ny >= 0)
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
	cin >> sx1 >> sy1;
	cin >> sx2 >> sy2;
	sx1--;
	sy1--;
	sx2--;
	sy2--;
	bfs(sx1,sy1);
	cout << endl;
	for(int i = 0;i <= 20;i++)
	{
	    for(int j = 0;j <= 20;j++)
	    {
	        vis[i][j] = false;
	    }
	}
	bfs(sx2,sy2);
	return 0;
}