#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

int a[10090],b[10090], x[10090];

void s2(string s, int a[]){
    a[0] = s.size();
    for(int i = 1;i <= a[0];i++)
    {
        a[i] = s[a[0] - i] - '0';
    }
}
void print(int a[]){
    for(int i = a[0]; i >= 1;i--)
    {
        cout << a[i];
    }
}
void add(int a[],int b[],int c[]){
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
void i2(int n,int a[]){
    while(n>0){
        a[++a[0]] = n % 10;
        n/=10;
    }
    if(a[0] == 0)
    {
        a[0]++;
    }
}
bool cmp(int a[],int b[]){
    if(a[0] != b[0])
    {
        return a[0] > b[0];
    }
    for(int i = a[0];i >= 1; i--)
    {
        if(a[i]!=b[i]) return a[i] > b[i];
    }
    return 1;
}
void sub(int a[],int b[],int c[]){
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

int main() {
    string sa,sb;
    cin >> sa >> sb;
    s2(sa,a);
    s2(sb,b);
	if(cmp(a,b))
	{
	    sub(a,b,x);
	    print(x);
	}
	else
	{
	    sub(b,a,x);
	    cout << '-';
	    print(x);
	}
	return 0;
}