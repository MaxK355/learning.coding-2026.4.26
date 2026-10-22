#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int n, x, h[1005], cnt = 0;

int main() {
	cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> x;
        for(int j = 1; j <= n;j++)
        {
            if(h[j] >= x)
            {
                h[j] = x;
                break;
            }
            else if(h[j] == 0)
            {
                cnt++;
                h[j] = x;
                break;
            }
        }
    }
    cout << cnt;
    return 0;
}