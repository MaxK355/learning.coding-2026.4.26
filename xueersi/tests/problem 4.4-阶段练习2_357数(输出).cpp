#include <iostream>

using namespace std;

int a[20],n;

void dfs(int step,bool d,bool b, bool c)
{
    if(step == n) 
    {
        if( d && b && c)
        {
            long long num = 0;
            for(int i = 0;i < n;i++)
            {
                num = num * 10 + a[i];
            }
            printf("%lld\n",num);
            return;
        }
        return;
    }
    if(step == 0 || a[step - 1] != 3)
    {
        a[step] = 3;
        dfs(step + 1,true,b,c);
    }
    if(step == 0 || a[step - 1] != 5)
    {
        a[step] = 5;
        dfs(step + 1,d,true,c);
    }
    if(step == 0 || a[step - 1] != 7)
    {
        a[step] = 7;
        dfs(step + 1,d,b,true);
    }
    return;
}

int main()
{
    cin >> n;
    dfs(0,false,false,false);
    return 0;
}