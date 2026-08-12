#include <iostream>
#include <cmath>
using namespace std;
int n, l[20];
long long ans = -1;
long long Calc(int a, int b, int c) {
    double p = (a + b + c)/ 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c)) * 100;
}
void DFS(int step, int a, int b, int c) {
    if (step > n) {
        if (a + b > c && a + c > b && b + c > a)
            ans = max(ans, Calc(a, b, c));
        return;
    }
    DFS(step + 1, a + l[step], b, c);
    DFS(step + 1, a, b + l[step], c);
    DFS(step + 1, a, b, c + l[step]);
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> l[i];
    DFS(1, 0, 0, 0);
	cout << ans << endl;
    return 0;
}
/*
1、A：0         B：1          C：-1          D：10000 
2、A：int       B：double     C：long long   D：bool 
3、A：(a + b + c) * (1 / 2) * 1.0     
   B：(a + b + c) / 2     
   C：(a + b + c) * (1 / 2)   
   D：(a + b + c) / 2.0   
4、A：a + b > c || b + c > a  
   B：a + b > c || a + c > b || b + c > a
   C：a + b > c && a + c > b && b + c > a  
   D：a + b > c && b + c > a  
5、第 ⑤空16~18行处，依次应该填写的是 
   A：step + 1   step + 1   step + 1 
   B：step       step       step 
   C：step - 1   step - 1   step - 1 
   D：step - 1   step       step + 1   
*/

