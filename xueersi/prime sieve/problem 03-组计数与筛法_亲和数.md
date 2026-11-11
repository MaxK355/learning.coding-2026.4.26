# 题目描述

记 $d(n)$ 为 $n$ 的所有真因数（小于 $n$ 且整除 $n$ 的正整数）之和。

如果 $d(a)=b$ 且 $d(b)=a$，且 $a \neq b$，那么 $a$ 和 $b$ 构成一个亲和数对。

例如，220的真因数包括1、2、4、5、10、11、20、22、44、55和110，因此 $d(220)=284$；而284的真因数包括1、2、4、71和142，因此 $d(284)=220$。

输入正整数 $M$，若一个亲和数对中两个数都小于 $M$，这个亲和数对就小于 $M$，求所有小于 $M$ 的亲和数对的和。

## 输入描述

一个整数 $M$ ($300 \le M \le 2000000$)

## 输出描述

输出所有小于 $M$ 的亲和数对的和

## 样例1

**输入**
```
300
```

**输出**
```
504
```

## 提示

## 代码

```cpp
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int m, f[2000005], sum = 0;

void primes(int n){
    f[1] = 0;
    for(int i = 2;i <= n;i++)
    {
        f[i] += 1;
        for(int j = 2;j * i <= n;j++)
        {
            f[i * j] += i;
        }
    }
}

int main(){
    cin >> m;
    primes(m);
    for(int i = 1; i < m;i++)
    {
        int b = f[i];
        if(i < b && b < m && f[b] == i)
        {
            sum += i + b;
        }
    }
    cout << sum;
    return 0;
}
```