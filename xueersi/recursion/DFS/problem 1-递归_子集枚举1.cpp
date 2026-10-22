#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int n;
bool vis[100];

void dfs(int step)
{
    if(step > n)
    {
        for(int i = 1;i <= n;i++)
        {
            if(vis[i])
            {
                cout << i << ' ';
            }
        }
        cout << endl;
        return;
    }
    for(int i = 1;i >= 0;i--)
    {
        vis[step] = i;
        dfs(step + 1);
    }
}

int main(){
    cin >> n;
    dfs(1);
	return 0;
}