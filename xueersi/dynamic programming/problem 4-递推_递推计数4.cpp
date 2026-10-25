#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
LL a[50],b[50];
//a[n]表示以5结尾的n位数个数
//b[n]表示不以5结尾的n位数个数
int main(){
    int n;
    cin>>n;
    a[1]= 1;//作答区域
    b[1]= 8;//作答区域
    for(int i=2;i<=n;i++){
        a[i] = a[i - 1] + b[i - 1];//作答区域
        b[i] = (a[i - 1] * 8) + b[i - 1] * 9;//作答区域
    }
    cout<< a[n] + b[n]<<endl;//作答区域
    return 0;
}