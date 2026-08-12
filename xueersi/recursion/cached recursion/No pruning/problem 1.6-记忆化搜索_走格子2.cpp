#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 998244353;


ll n,m,a[1005][1005],mem[1005][1005];

ll dfs(int x,int y)
{
    if(x > n || y > m)
    {
        return 0;
    }
    if(x == n && y == m)
    {
        return 1;
    }
    if(a[x][y] == 0)
    {
        return 0;
    }
    if(mem[x][y] != -1)
    {
        return mem[x][y];
    }
    mem[x][y] = 0;
    for(int i = 1;i <= a[x][y];i++)
    {
        mem[x][y] = (mem[x][y] + dfs(x + i,y)) % mod;
    }
    for(int i = 1;i <= a[x][y];i++)
    {
        mem[x][y] = (mem[x][y] + dfs(x,y + i)) % mod;
    }
    return mem[x][y];
}

int main() {
	scanf("%lld %lld", &n, &m);
	memset(mem,-1,sizeof(mem));
	for(int i = 1;i <= n;i++)
	{
	    for(int j = 1;j <= m;j++)
	    {
	        scanf("%lld",&a[i][j]);
	    }
	}
	cout << dfs(1,1);
    return 0;
}