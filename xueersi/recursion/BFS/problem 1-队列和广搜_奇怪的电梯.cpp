#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int n, a, b, k[205];
struct node {
    int x, step;
};
bool vis[205];

int bfs() {
    queue<node> q;
    q.push({a, 0});
    vis[a] = 1;
    while (!q.empty()) {
        node cur = q.front();
        q.pop();
        if (cur.x == b) {
            return cur.step;
        }
        int up = cur.x + k[cur.x];
        if (up >= 1 && up <= n && !vis[up]) {
            q.push({up, cur.step + 1});
            vis[up] = 1;
        }
        int down = cur.x - k[cur.x];
        if (down >= 1 && down <= n && !vis[down]) {
            q.push({down, cur.step + 1});
            vis[down] = 1;
        }
    }
    return -1;
}

int main() {
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
    }
    cout << bfs();
    return 0;
}
