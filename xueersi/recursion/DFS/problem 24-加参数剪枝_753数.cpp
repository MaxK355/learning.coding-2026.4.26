#include <iostream>
#include <cmath>
using namespace std;

int a[20],cnt = 0,num,lim;

void dfs(int step,int n,bool d,bool b, bool c)
{
    if(step == n) 
    {
        if( d && b && c)
        {
            num = 0;
            for(int i = 0;i < n;i++)
            {
                num = num * 10 + a[i];
            }
            if(num <= lim)
            {
                cnt++;
            }
            return;
        }
        return;
    }
    a[step] = 3;
    dfs(step + 1,n,true,b,c);
    a[step] = 5;
    dfs(step + 1,n,d,true,c);
    a[step] = 7;
    dfs(step + 1,n,d,b,true);
    return;
}

int main()
{
    cin >> lim;
    for(int i = 3;i <= floor(log10(lim)) + 1;i++)
    {
        dfs(0, i,false,false,false);
    }
    cout << cnt;
    return 0;
}