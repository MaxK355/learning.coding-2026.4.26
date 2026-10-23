#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
char map_[105][105];
bool vis[105][105];
int sizes[11000]; 
int dx[8] = {0,0,1,1,1,-1,-1,-1};
int dy[8] = {1,-1,1,0,-1,1,0,-1};
int mark(int x, int y) 
{
    int current_size = 1;
    for(int i = 0; i < 8; i++) 
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && ny >= 0 && nx < n && ny < m) 
        {
            if(map_[nx][ny] == 'W' && !vis[nx][ny]) 
            {
                vis[nx][ny] = 1;
                current_size += mark(nx, ny);
            }
        }
    }
    return current_size;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) 
    {
        for(int j = 0; j < m; j++) 
        {
            cin >> map_[i][j];
        }
    }
    int cnt = 0; 
    for(int i = 0; i < n; i++) 
    {
        for(int j = 0; j < m; j++) 
        {
            if(map_[i][j] == 'W' && !vis[i][j]) 
            {
                vis[i][j] = 1;
                sizes[cnt] = mark(i, j); 
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    sort(sizes, sizes + cnt);
    for(int i = 0; i < cnt; i++) 
    {
        cout << sizes[i] << ' ';
    }
    return 0;
}
