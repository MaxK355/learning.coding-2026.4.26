#include<cstdio>
#include<iostream>
using namespace std;
int n,w[105],ans;
void dfs(int index,int left,int right)
{
    if(index == n)
    {
        if(left == right)
        {
            ans++;
        }
        return;
    }
    dfs(index + 1,left+w[index],right);
    dfs(index + 1,left,right+w[index]);
    dfs(index + 1,left, right);
}
int main()
{
    cin >> n;
	for(int i = 0;i < n;i++)
	{
	    cin >> w[i];
	}
	dfs(0,0,0);
	cout << ans;
	return 0;
}