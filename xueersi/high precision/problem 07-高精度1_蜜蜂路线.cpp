#include<algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
int f[4005][1005];
void s2(string s, int a[])
{
    a[0] = s.size();
    for(int i = 1;i <= a[0];i++)
    {
        a[i] = s[a[0] - i] - '0';
    }
}
void print(int a[])
{
    for(int i = a[0]; i >= 1;i--)
    {
        cout << a[i];
    }
}
void add(int a[],int b[],int c[])
{
    c[0]= max(b[0],a[0]);
    int u = 0;
    for(int i = 1;i <= c[0];i++)
    {
        int t = a[i] + b[i] + u;
        c[i] = t % 10;
        u = t / 10;
    }
    if(u > 0)
    {
        c[++c[0]] = u;
    }
}

void i2(int n,int a[])
{
    while(n>0){
        a[++a[0]] = n % 10;
        n/=10;
    }
    if(a[0] == 0)
    {
        a[0]++;
    }
}

int main() {
	int n,m;
	cin >> m >> n;
	int d = n - m;
	i2(1,f[1]);
	i2(1,f[2]);
	for(int i = 3;i <= d + 1;i++)
	{
	    add(f[i-1],f[i-2],f[i]);
	}
	print(f[d+1]);
    return 0;
}