#include <iostream>
using namespace std;
void s2BIG(string s, int a[])
{
    a[0]=s.size();
    for(int i=1; i<=a[0]; i++)
        a[i]=s[a[0]-i]-'0';
}
void printBIG(int a[])
{
    for(int i=a[0]; i>=1; i--)
        cout << a[i];
    cout << endl;
}
void mulBIG(int a[],int b,int c[])
{
    c[0] = a[0];
    int u = 0;
    for(int i = 1;i <= c[0];i++)
    {
        int t = a[i] * b + u;
        c[i] = t % 10;
        u = t / 10;
    }
    while(u > 0)
    {
        c[++c[0]] = u % 10;
        u /= 10;
    }
}
int check(int a[],int b)
{
    int cnt = 0;
    for(int i=a[0]; i>=1; i--)
    {
        if(a[i] == b)
        {
            cnt++;
        }
    }
    return cnt;
}
string s = "1";
int b[1000005],n,a,c[1000005];
int main()
{
    cin >> n >> a;
    s2BIG(s,b);
    for(int i = 1;i <= n;i++)
    {
        if(i % 2 == 1)
        {
            mulBIG(b,i,c);
        }
        else
        {
            mulBIG(c,i,b);
        }
    }
    if(n % 2 == 1)
    {
        cout << check(c,a);
    }
    else
    {
        cout << check(b,a);
    }
    return 0;
}