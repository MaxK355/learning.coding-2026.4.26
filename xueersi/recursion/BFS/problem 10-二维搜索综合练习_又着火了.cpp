#include<cstdio> 
#include<iostream> 
#include<algorithm> 
#include <queue> 
using namespace std; 

bool fire[2005][2005]; 
int timeof[2005][2005]; 
int dx[4] = {0,0,1,-1}; 
int dy[4] = {1,-1,0,0}; 
int k, tempx, tempy, n, m, maxn = 0; 

struct node{ 
    int x,y; 
} a[15]; 

void bfs() { 
    queue<node> q; 
    for(int i = 1; i <= k; i++)
    { 
        q.push({a[i].x, a[i].y}); 
        fire[a[i].x][a[i].y] = 1; 
    } 
    while(!q.empty()) 
    { 
        node cur = q.front(); 
        q.pop(); 
        for(int i = 0; i < 4; i++) 
        { 
            int nx = cur.x + dx[i]; 
            int ny = cur.y + dy[i]; 
            if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && !fire[nx][ny])
            { 
                q.push({nx, ny}); 
                fire[nx][ny] = 1; 
                timeof[nx][ny] = timeof[cur.x][cur.y] + 1; 
                maxn = timeof[nx][ny]; 
            } 
        } 
    } 
    return; 
} 

int main(){ 
    cin >> n >> m; 
    cin >> k; 
    for(int i = 1; i <= k; i++) 
    {
        cin >> a[i].x >> a[i].y; 
    } 
    
    bfs(); 
    
    for(int i = 1; i <= n; i++) 
    { 
        for(int j = 1; j <= m; j++) 
        { 
            if(timeof[i][j] == maxn) 
            { 
                cout << i << ' ' << j << "\n";
            } 
        } 
    } 
    return 0; 
}
