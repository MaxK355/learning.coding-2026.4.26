#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
int f[50];
//f[n]表示上n级台阶的方法数
int main(){
    int n;
    cin >> n;
    f[1] = 1; //作答区域
    f[2] = 2; //作答区域
    for (int i = 3; i <= n; i++){
        //作答区域
        f[i] = f[i - 1] + f[i - 2];
    }
    cout << f[n] << endl;
    return 0;
}