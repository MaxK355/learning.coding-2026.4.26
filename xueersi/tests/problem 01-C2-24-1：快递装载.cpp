#include <iostream>
#include <algorithm>
using namespace std;

int n, c, w[105] = {},ans = 0;

bool cmp(int x,int y)
{
    return x < y;
}

int main()
{
    cin >> n >> c;
    for(int i = 0;i < n;i++)
    {
        cin >> w[i];
    }
    sort(w, w + n, cmp);
    for(int i = 0;i < n;i++)
    {
        if(c - w[i] >= 0)
        {
            c -= w[i];
            ans++;
        }
        else
        {
            break;
        }
    }
    cout << ans;
	return 0;
}