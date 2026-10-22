#include <iostream>
#include <cstdio>
using namespace std;
int n, k ,a[25];
void dfs(int step,int sum)
{
    if(sum > n)
    {
        return;
    }
    if(step > k)
    {
        if(sum == n)
        {
            for(int i = 1;i <= k;i++)
            {
                cout << a[i] << " ";
            }
            cout << endl;
        }
        return;
    }
    for(int i = 1;i <= n;i++)
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
    cin >> n >> k;
    dfs(1,0);
    return 0;
}