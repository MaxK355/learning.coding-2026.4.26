#include <iostream>
using namespace std;

int n,cnt = 0;
int useable[17][17] = {};
char input;

void dfs(int step)
{
    if(step == n)
    {
        cnt++;
        return;
    }
    for(int i = 0;i < n;i++)
    {
        if(useable[step][i] == 0)
        {
            for(int j=0;j<n;j++)
            {
                if(j+step<n) 
                {
                    useable[step+j][i]++;
                }
                if(j+step<n&&i+j<n)
                {
                    useable[step+j][i+j]++;
                }
                if(i-j>=0&&step+j<n) 
                {
                    useable[step+j][i-j]++;
                }
            }
            dfs(step + 1);
            for(int j=0;j<n;j++)
            {
                if(j+step<n) 
                {
                    useable[step+j][i]--;
                }
                if(j+step<n&&i+j<n)
                {
                    useable[step+j][i+j]--;
                }
                if(i-j>=0&&step+j<n) 
                {
                    useable[step+j][i-j]--;
                }
            }
        }
    }
}

int main()
{
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            cin >> input;
            if(input == '.')
            {
                useable[i][j] = 1;
            }
        }
    }
    dfs(0);
    cout << cnt;
}