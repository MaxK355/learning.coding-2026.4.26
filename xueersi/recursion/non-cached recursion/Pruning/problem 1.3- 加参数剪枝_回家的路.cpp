#include <iostream>
using namespace std;
int n,a[105],d,cnt = 0;
int main()
{
    cin >> n >> d;
    string s;
    cin >> s;
    for(int i = 0;i < n;i++)
    {
        a[i] = s[i] - '0';
    }
    int cur_pos = 0, flag = 0;
    while(cur_pos != n - 1)
    {
        flag++;
        if(cur_pos + d >= n - 1)
        {
            cnt++;
            cout << cnt;
            return 0;
        }
        for(int i = cur_pos + d;i > cur_pos;i--)
        {
            if(a[i] == 1)
            {
                cur_pos = i;
                cnt++;
                break;
            }
        }
        if(flag > n)
        {
            cout << -1;
            return 0;
        }
    }
    return 0;
}