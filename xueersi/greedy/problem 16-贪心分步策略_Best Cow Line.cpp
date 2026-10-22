#include <iostream>
using namespace std;

char s[2005];
int n;

bool check(int l, int r)
{
    for(int i = 0; l + i <= r - i;i++)
    {
        if(s[l+i] != s[r-i])
        {
            return s[l + i] < s[r - i];
        }
    }
    return true;
}

int main()
{
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        cin >> s[i];
    }
    int l = 0,r = n - 1;
    for(int i = 0;i < n;i++)
    {
        if(check(l, r))
        {
            cout << s[l++];
        }
        else
        {
            cout << s[r--];
        }
        if(i % 80 == 79)
        {
            cout << endl;
        }
    }
    return 0;
}