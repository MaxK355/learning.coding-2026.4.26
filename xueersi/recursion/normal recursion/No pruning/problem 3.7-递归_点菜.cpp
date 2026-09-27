#include <iostream>
using namespace std;

int n, p[15], m, cnt = 0;

void dfs(int step,int spend)
{
    if(spend == m)
    {
        cnt++;
        return;
    }
    if(step > n)
    {
        return;
    }
    dfs(step + 1,spend + p[step]);
    dfs(step + 1,spend);
    return;
}

int main()
{
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> p[i];
    }
    dfs(1,0);
    cout << cnt;
	return 0;
}