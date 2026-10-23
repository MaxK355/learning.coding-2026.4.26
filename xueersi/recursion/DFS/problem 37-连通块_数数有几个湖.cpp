#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n, m;
int cnt;
char map_[105][105];
bool vis[105][105];
int dx[8] = {0,0,1,1,1,-1,-1,-1};
int dy[8] = {1,-1,1,0,-1,1,0,-1};

void mark(int x,int y)
{
    for(int i = 0;i < 8;i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && ny >= 0 && nx < n && ny < m)
        {
            if(map_[nx][ny] == 'W' && !vis[nx][ny])
            {
                vis[nx][ny] = 1;
                mark(nx,ny);
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++)
        {
            cin >> map_[i][j];
        }
    }
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++)
        {
            if(map_[i][j] == 'W' && !vis[i][j])
            {
                cnt++;
                vis[i][j] = 1;
                mark(i,j);
            }
        }
    }
    cout << cnt;
	return 0;
}