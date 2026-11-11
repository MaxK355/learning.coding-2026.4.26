#include <iostream>
using namespace std;
int n, k, ans ,a[10];
void dfs(int step,int sum)
{
    if(step > k)
    {
        if(sum == n)
        {
            ans++;
        }
        return;
    }
    for(int i = a[step - 1];i <= n - sum;i++)
    {
        a[step] = i;
        dfs(step + 1,sum + i);
    }
}
int main()
{
    cin >> n >> k;
    a[0] = 1;
    dfs(1,0);
    cout << ans;
    return 0;
}