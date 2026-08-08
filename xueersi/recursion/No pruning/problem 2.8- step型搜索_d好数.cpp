#include <cstdio>
#include <iostream>
using namespace std;

int n, d, a[100], cnt = 0,m;

void dfs(int step)
{
    if(step > n)
    {
        cnt++;
        return;
    }
    for(int i = 1;i <= m;i++)
    {
        if((abs(i - a[step-1]) <= d) || (step == 1))
        {
            a[step] = i;
            dfs(step + 1);
        }
    }
}

int main()
{
    cin >> n >> m >> d;;
    dfs(1);
    cout << cnt;
    return 0;
}