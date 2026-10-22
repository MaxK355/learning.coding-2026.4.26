#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
struct node{
    int start,end;
} a[50005];

bool cmp(node &x,node &y)
{
    return x.start < y.start;
}

int n;

int main()
{
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i].start >> a[i].end;
    }
    sort(a+1,a+n+1,cmp);
    int last = 1;
    for(int i = 2;i <= n;i++)
    {
        if(a[i].start <= a[last].end)
        {
            if(a[i].end > a[last].end)
            {
                a[last].end = a[i].end;
            }
        }
        else
        {
            last++;
            a[last]=a[i];
        }
    }
    for(int i = 1;i <= last;i++)
    {
        cout << a[i].start << " " << a[i].end << endl;
    }
}