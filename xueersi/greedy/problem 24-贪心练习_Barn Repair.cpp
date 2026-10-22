#include <iostream>
#include <algorithm>
using namespace std;

int m, s, c, a[205], k[205];

bool cmp(int x, int y){
    return x > y;
}

int main()
{
    cin >> m >> s >> c;
    if(m >= c)
    {
        cout << c;
        return 0;
    }
    for(int i = 1;i <= c;i++)
    {
        cin >> a[i];
    }
    sort(a + 1,a + c + 1);
    for(int i = 1;i <= c - 1;i++)
    {
        k[i] = a[i + 1] - a[i] - 1;
    }
    sort(k + 1, k + c, cmp);
    int L = a[c] - a[1] + 1;
    for(int i = 1;i < m;i++){
        L -= k[i];
    }
    cout << L;
    return 0;
}