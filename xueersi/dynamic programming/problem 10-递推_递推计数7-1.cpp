#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
LL a[50],b[50],c[50],d[50],e[50],f[50];
int main(){
    int n;
    cin>>n;
    a[0]=1;
    b[0]=0;
    c[0]=0;
    d[0]=0;
    e[0]=0;
    f[0]=0;
    for(int i=1;i<=n;i++){
        a[i]= b[i - 1] + f[i -1];//作答区域
        b[i]= a[i - 1] + c[i -1];//作答区域
        c[i]= b[i - 1] + d[i -1];//作答区域
        d[i]= c[i - 1] + e[i -1];//作答区域
        e[i]= d[i - 1] + f[i -1];//作答区域
        f[i]= a[i - 1] + e[i -1];//作答区域
    }
    cout<< b[n] <<endl;//作答区域
    cout<< d[n] <<endl;//作答区域
    return 0;
}