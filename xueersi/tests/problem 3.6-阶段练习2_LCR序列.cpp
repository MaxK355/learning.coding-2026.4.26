#include <iostream>
#include <string>
using namespace std;

int n;
string ans;

void dfs(int step)
{
    if(step == n)
    {
        cout << ans << endl;
        return;
    }
    ans = ans + 'C';
    dfs(step + 1);
    ans.pop_back();
    ans = ans + 'L';
    dfs(step + 1);
    ans.pop_back();
    ans = ans + 'R';
    dfs(step + 1);
    ans.pop_back();
    return;
    
}

int main()
{
    cin >> n;
    dfs(0);
    return 0;
}