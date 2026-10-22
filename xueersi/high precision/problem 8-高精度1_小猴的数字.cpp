#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int a[3005],b[3005], c[3005];

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
bool cmp(int a[],int b[])
{
    if(a[0] != b[0])
    {
        return a[0] > b[0];
    }
    for(int i = a[0];i >= 1; i--)
    {
        if(a[i]!=b[i]) return a[i] > b[i];
    }
    return 0;
}
void sub(int a[],int b[],int c[])
{
    c[0] = max(a[0], b[0]);
    int u = 0;
    for(int i = 1;i <= c[0];i++)
    {
        int t = a[i] - b[i] - u;
        if(t < 0)
        {
            u = 1;
            c[i] = t + 10;
        }
        else
        {
            u = 0;
            c[i] = t;
        }
    }
    while(c[c[0]] == 0 && c[0] > 1)
    {
        c[0]--;
    }
}
int l,r;
int l1,r1;
string sa,sb;

int main() {
	cin >> l >> r;
	cin >> l1 >> r1;
	for(int i = l;i <= r;i++)
	{
	    sa = sa + to_string(i);
	}
	for(int i = l1;i <= r1;i++)
	{
	    sb = sb + to_string(i);
	}
	s2(sa, a);
	s2(sb, b);
	add(a,b,c);
	print(c);
    return 0;
}