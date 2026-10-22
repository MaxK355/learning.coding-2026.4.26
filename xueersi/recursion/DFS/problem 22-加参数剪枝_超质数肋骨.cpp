#include <iostream>
using namespace std;
int n;

bool prime(int x)
{
    if(x <= 1)
    {
        return false;
    }
    for(int i = 2;i * i <= x;i++)
    {
        if(x%i == 0)
        {
            return false;
        }
    }
    return true;
}
void dfs(int step,int num)
{
    if(step > n)
    {
        cout<< num << "\n";
        return;
    }
    for(int i = 1;i <= 9;i++)
    {
        int newnum = num * 10 + i;
        if(prime(newnum))
        {
            dfs(step + 1,newnum);
        }
    }
}
int main()
{
    cin >> n;
    dfs(1,0);
    return 0;
}