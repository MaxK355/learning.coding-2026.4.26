#include <iostream>
#include <algorithm>
using namespace std;

int n, ans = 0;

struct node{
    int l, r;
}a[1005];

bool cmp(node x, node y){
    return x.r < y.r;
}

int main(){
    cin >> n;
    char placeholder;
    int num;
    for(int i = 0;i < n;i++)
    {
        cin >> num >> placeholder;
        a[i].l += 100 * num;
        cin >> num;
        a[i].l += num;
        cin >> num >> placeholder;
        a[i].r += 100 * num;
        cin >> num;
        a[i].r += num;
    }
    sort(a, a + n,cmp);
    int pos = 0;
    for(int i = 0;i < n;i++)
    {
        if(pos < a[i].l)
        {
            pos = a[i].r;
            ans++;
        }
    }
    cout << ans;
    return 0;
}