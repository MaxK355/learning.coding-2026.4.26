#include <cstdio>
#include <iostream>
using namespace std;

int n, k, a[100], cnt = 0;

void dfs(int step)
{
    if(step > n)
    {
        cnt++;
        if(cnt == k)
        {
            for(int i = 1;i <= n;i++)
            {
                cout << a[i];
            }
            exit(0);
        }
        return;
    }
    for(int i = 1;i <= 9;i++)
    {
        if(i >= a[step - 1])
        {
            a[step] = i;
            dfs(step + 1);
        }
    }
}

int main()
{
    cin >> n >> k;
    dfs(1);
    return 0;
}