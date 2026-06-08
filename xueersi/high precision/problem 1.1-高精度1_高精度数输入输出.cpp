#include <iostream>
#include <cstdio>
using namespace std;

int a[1005];

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

int main()
{
    string s;
    cin>>s;
    s2(s,a);
    print(a);
    return 0;
}
