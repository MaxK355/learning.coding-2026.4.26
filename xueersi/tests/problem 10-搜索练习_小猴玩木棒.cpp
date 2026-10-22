#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,m,a[25],sum = 0,len[25];
bool vis[25],flag;

void dfs(int step)
{
    if(step == m)
    {
        cout << "yes" << endl;
        flag = true;
        return;
    }
    if(flag)
    {
        return;
    }
    for(int i = 1;i <= 4;i++)
    {
        if(len[i] + a[step] <= sum)
        {
            len[i] += a[step];
            dfs(step + 1);
            len[i] -= a[step];
        }
    }
    return;
}

int main() {
	cin >> n;
	for(int i = 0;i < n;i++)
	{
	    cin >> m;
	    sum = 0;
	    for(int j = 0;j < m;j++)
	    {
	        cin >> a[j];
	        sum += a[j];
	    }
	    if(sum % 4 != 0)
	    {
	        cout << "no" << endl;
	    }
	    else
	    {
	        sum /= 4;
	        dfs(0);
	        if(!flag)
	        {
	            cout << "no" << endl;
	        }
	        flag = false;
	        sum = 0;
	    }
	    for(int i = 0;i < 25;i++)
	    {
	        vis[i] = false;
	    }
	}
    return 0;
}