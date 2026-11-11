#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
long long cnt[100005] = {};
int k,a[25],n;
void recur(int step,int num)
{
    if(step > n)
    {
        cnt[num % k]++;
        return;
    }
    recur(step + 1,num + a[step]);
    recur(step + 1,num);
}
int main(){
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
	{
	    cin >> a[i];
	}
	recur(1,0);
	for(int i = 0;i < k;i++)
	{
	    cout << cnt[i] << endl;
	}
	return 0;
}