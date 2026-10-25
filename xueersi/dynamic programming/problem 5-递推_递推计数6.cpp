#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
LL x[50],y[50];
//x[n]表示包含偶数个1的n位数的个数
//y[n]表示包含奇数个1的n位数的个数
int main(){
    int n;
    cin>>n;
    x[1]= 8;//作答区域
    y[1]= 1;//作答区域
    for(int i=2;i<=n;i++){
        x[i]= y[i - 1] + x[i - 1] * 9;//作答区域
        y[i]= x[i - 1] + y[i - 1] * 9;//作答区域
    }
    cout<<x[n]<<endl;
    return 0;
}