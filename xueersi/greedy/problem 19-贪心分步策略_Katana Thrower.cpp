#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

struct node{
    int a, b;
} s[100005];

bool cmp(node x,node y)
{
    return x.b > y.b;
}

int n,h,cnt,maxa;

int main() {
    cin >> n >> h;
    for(int i=1;i<=n;i++)
    {
        cin >> s[i].a >>s[i].b;
        maxa=max(maxa,s[i].a);
    }
    sort(s+1,s+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        if(s[i].b > maxa)
        {
            cnt++;
            h -= s[i].b;
            if(h <=0)
            {
                cout << cnt;
                return 0;
            }
        }
        else
        {
            break;
        }
    }
    cnt += ceil((double)h / maxa);
    cout << cnt;
    return 0;
}