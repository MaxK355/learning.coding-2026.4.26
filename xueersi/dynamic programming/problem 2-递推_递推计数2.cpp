#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
int f[50];
//f[n]表示只由1,3,4组成的数码和为n的数的个数
int main(){
    int n;
    cin>>n;
    f[1]= 1;//作答区域
    f[2]= 1;//作答区域
	f[3]= 2;//作答区域
	f[4]= 4;//作答区域
    for(int i=5;i<=n;i++)
    {
         f[i] = f[i - 1] + f[i - 3] + f[i - 4];//作答区域
    }
    cout<<f[n]<<endl;
    return 0;
}