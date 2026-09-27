#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int n, a[15],useable[15][15];
bool vis[15];

bool check()
{
    for(int i = 1;i <= n;i++)
    {
        for(int j = i + 1;j <= n;j++)
        {
            if(a[j] == a[i] || i + a[i] == j + a[j] || i - a[i] == j - a[j])
            {
                return false;
            }
        }
    }
    return true;
}

void dfs(int step)
{
    if(step > n)
    {
        if(check())
        {
            for(int i = 1;i <= n;i++)
            {
                cout << a[i] << ' ';
            }
            exit(0);
        }
        return;
    }
    for(int i = 1;i <= n;i++)
    {
        if(!vis[i])
        {
            a[step] = i;
            vis[i] = 1;
            dfs(step + 1);
            vis[i] = 0;
        }
    }
}

int main(){
	cin >> n;
	dfs(1);
	return 0;
}