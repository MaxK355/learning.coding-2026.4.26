#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
char map_[1005][1005];
bool vis[1005][1005];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void mark(int x, int y) 
{
    for(int i = 0; i < 4; i++) 
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && ny >= 0 && nx < n && ny < m) 
        {
            if(map_[nx][ny] == '#' && !vis[nx][ny]) 
            {
                vis[nx][ny] = 1;
                mark(nx, ny);
            }
        }
    }
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
    for(int i = 0; i < n - 1; i++) 
    {
        for(int j = 0; j < m - 1; j++) 
        {
            int count = (map_[i][j] == '#') + (map_[i+1][j] == '#') + 
                        (map_[i][j+1] == '#') + (map_[i+1][j+1] == '#');
            if (count == 3) 
            {
                cout << "Bad placement." << endl;
                return 0;
            }
        }
    }
    int cnt = 0; 
    for(int i = 0; i < n; i++) 
    {
        for(int j = 0; j < m; j++) 
        {
            if(map_[i][j] == '#' && !vis[i][j]) 
            {
                vis[i][j] = 1;
                mark(i, j); 
                cnt++;
            }
        }
    }

    cout << "There are " << cnt << " ships." << endl;
    return 0;
}
