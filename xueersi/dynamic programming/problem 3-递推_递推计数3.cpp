#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
int a[50],b[50],c[50];
//a[n]表示以1结尾的数的n位数的个数
//b[n]表示以2结尾的数的n位数的个数
//c[n]表示以3结尾的数的n位数的个数
int main(){
    int n;
    cin>>n;
    a[1]= 1;//作答区域
    b[1]= 1;//作答区域
    c[1]= 1;//作答区域
    for(int i=2;i<=n;i++){
        a[i]= b[i - 1] + c[i - 1];//作答区域
        b[i]= a[i - 1] + b[i - 1] + c[i - 1];//作答区域
        c[i]= b[i - 1] + a[i - 1] + c[i - 1];//作答区域
    }
    cout<< a[n] + b[n] + c[n]<<endl;//作答区域
    return 0;
}