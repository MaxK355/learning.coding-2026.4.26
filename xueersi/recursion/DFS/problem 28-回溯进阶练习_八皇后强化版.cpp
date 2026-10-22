#include <iostream>
#include <cstdlib>
using namespace std;

int n,cnt = 0, k;
int useable[25][25] = {};
int ans[25][25];
char input;

void dfs(int step)
{
    if(step == n)
    {
        cnt++;
        if(cnt <= k)
        {
            for(int i = 0;i < n;i++)
            {
                for(int j = 0;j < n;j++)
                {
                    if(ans[i][j] == 1)
                    {
                        cout << j + 1 << ' ';
                    }
                }
            }
            cout << endl;
        }
        else
        {
            exit(0);
        }
        return;
    }
    for(int i = 0;i < n;i++)
    {
        if(useable[step][i] == 0)
        {
            ans[step][i] = 1;
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
            ans[step][i] = 0;
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
    cin >> n >> k;
    dfs(0);
}