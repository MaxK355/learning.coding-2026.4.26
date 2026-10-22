#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,nums[100005];
int jump(int nums[]) {
    int jumps=0;
    if(n == 1)
    {
        return 0;
    }
    for(int i=0;i<n;)
    {
        int max=-1,index;
        for(int j=1;j<=nums[i];j++)
        {
            if(i+nums[i]>=n - 1)
            {
                return jumps+1;
            }
            if(i+j<n)
            {
                if(j+nums[i+j]>max)
                {
                    max=j+nums[i+j];
                    index=i+j;
                }
            }
            else
            {
                break;
            }
        }
        jumps++;
        i=index;
    }
    return jumps;
}

int main()
{
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        cin >> nums[i];
    }
    cout << jump(nums);
    return 0;
}