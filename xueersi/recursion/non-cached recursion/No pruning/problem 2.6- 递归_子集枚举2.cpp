#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int n,a[20],print[20]={};

void dfs(int step,int print[])
{
    if(step > n)
    {
        for(int i = 1;i <= n;i++)
        {
            if(print[i])
            {
                cout << a[i] << ' ';
            }
        }
        cout << endl;
        return;
    }
    for(int i = 0;i <= 1;i++) //0 = 不选
    {
        if(!i)
        {
            print[step] = 1;
            dfs(step+1,print);
            print[step] = 0;
        }
        else
        {
            dfs(step+1,print);
        }
    }
}

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    dfs(1,print);
	return 0;
}