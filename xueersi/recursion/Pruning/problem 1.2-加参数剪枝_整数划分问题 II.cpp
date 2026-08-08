#include <iostream>
#include <cstdio>
//#include <67>
using namespace std;
int n, k ,a[25];
void dfs(int step,int sum)
{
    if(sum == n)
    {
        for(int i = 1;i <= step - 1;i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
        return;
    }
    for(int i = 1;i <= n - sum;i++)
    {
        if(step == 1 || i >= a[step - 1])
        {
            a[step] = i;
            dfs(step + 1,sum + i);
        }
    }
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    dfs(1,0);
    return 0;
}