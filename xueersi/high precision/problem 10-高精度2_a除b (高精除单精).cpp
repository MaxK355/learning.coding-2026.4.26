#include<cstdio> 
#include<iostream> 
#include<string> 
#include<algorithm> 
using namespace std; 

string sa; 
int a[1005], b, c[1020]; 
void div(int a[], int b, int c[]) {
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

int main() { 
    cin >> sa >> b;
    s2arr(sa, a); 
    div(a, b, c); 
    print(c); 
    return 0; 
}
