#include <iostream>
#include <algorithm>
using namespace std;

struct node{
    int t,l;
} p[1000005];

bool cmp(node x,node y)
{
    return x.t < y.t;
}

int n;
double avg = 0;
int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> p[i].t;
        p[i].l=i;
    }
    sort(p+1,p+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        cout << p[i].l << ' ';
        avg += p[i].t * (n-i);
    }
    cout << endl;
    avg = avg / n;
    printf("%.2lf", avg);
    return 0;
}