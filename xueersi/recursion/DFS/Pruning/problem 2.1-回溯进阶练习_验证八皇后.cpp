#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int n, a[15],useable[15][15];

bool check()
{
    for(int i = 1;i <= n;i++)
    {
        for(int j = i + 1;j <= n;j++)
        {
            if(a[j] == a[i] || i + a[i] == j + a[j] || i - a[i] == j - a[j])
            {
                return false;
            }
        }
    }
    return true;
}

int main(){
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
	    cin >> a[i];
	}
	if(check())
	{
	    cout << "Yes" << endl;
	}
	else
	{
	    cout << "No" << endl;
	}
	return 0;
}