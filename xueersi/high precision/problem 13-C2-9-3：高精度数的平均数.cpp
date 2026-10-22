#include<cstdio> 
#include<iostream> 
#include<string> 
#include<algorithm> 
using namespace std; 

int a[1005], b[1005], c[1020]; 

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
} 

void s2arr(string sa, int a[]) { 
    a[0] = sa.size(); 
    for(int i = 1; i <= a[0]; i++) { 
        a[i] = sa[a[0]-i] - '0'; 
    } 
} 

void add(int a[], int b[], int c[]) 
{
    c[0] = max(a[0], b[0]);
    int u = 0; 
    for(int i = 1; i <= c[0]; i++) {
        
        int t = a[i] + b[i] + u;
        c[i] = t % 10;
        u = t / 10;
    }
    if(u > 0) 
    {
        c[++c[0]] = u;
    }
}

string sa,sb;

int main() { 
    cin >> sa >> sb;
    s2arr(sa,a);
    s2arr(sb,b);
    add(a,b,c);
    divi(c,2,c);
    print(c);
    return 0; 
}
