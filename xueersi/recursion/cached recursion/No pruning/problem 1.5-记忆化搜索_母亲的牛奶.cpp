#include<iostream>
#include<cstdio>
using namespace std;

int a, b, c,s[25],t,f[25][25][25];

void dfs(int x,int y, int z)
{
    if(f[x][y][z])
    {
        return;
    }
    f[x][y][z] = 1;
    if(x == 0)
    {
        s[z] = 1;
    }
    t = min(x,b - y);
    dfs(x-t,y+t,z);
    t = min(y,a - x);
    dfs(x+t,y-t,z);
    
    t = min(y,c - z);
    dfs(x,y-t,z+t);
    t = min(z,b - y);
    dfs(x,y+t,z-t);
    
    t = min(x,c - z);
    dfs(x-t,y,z+t);
    t = min(z,a - x);
    dfs(x+t,y,z-t);
}

int main() {

    cin >> a >> b >> c;
    dfs(0,0,c);
    {
        for(int i = 0;i <= c;i++)
        {
            if(s[i])
            {
                cout << i << ' ';
            }
        }
    }
    return 0;
}