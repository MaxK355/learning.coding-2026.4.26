#include <cstdio> 
#include <iostream> 
#include <string> 
#include <algorithm> 
using namespace std; 

// Array structures: index [0] stores the length of the digits
int ans[10005], b, c; 
void mult(int a[],int b,int c[])
{
    c[0] = a[0];
    int u = 0;
    for(int i = 1;i <= c[0];i++)
    {
        int t = a[i] * b + u;
        c[i] = t % 10;
        u = t / 10;
    }
    while(u > 0)
    {
        c[++c[0]] = u % 10;
        u /= 10;
    }
}

void divi(int a[], int b, int c[]) {
    c[0] = a[0]; 
    int t = 0;       
    for(int i = a[0]; i >= 1; i--) {
        int u = t * 10 + a[i]; 
        c[i] = u / b;
        t = u % b;   
    }
        while(c[0] > 1 && c[c[0]] == 0) {
        c[0]--;
    }
}

void print(int a[]) { 
    for(int i = a[0]; i >= 1; i--) { 
        cout << a[i]; 
    } 
    cout << endl;
} 

int main() { 
    cin >> b >> c;
    if (c > b - c) 
    {
        c = b - c; 
    }
    ans[0] = 1; 
    ans[1] = 1; 
    for(int i = 1; i <= c; i++) { 
        mult(ans, b - i + 1, ans); 
        divi(ans, i, ans); 
    } 
    print(ans); 
    return 0; 
}
