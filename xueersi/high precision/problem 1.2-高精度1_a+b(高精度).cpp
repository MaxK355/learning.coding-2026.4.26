#include<algorithm>
#include <iostream>
#include <cstdio>
using namespace std;

int a[1005],b[1005], c[1005];

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

string sa,sb;

int main() {
	cin >> sa >> sb;
	s2(sa, a);
	s2(sb, b);
	add(a,b,c);
	print(c);
    return 0;
}