#include<cstdio> 
#include<iostream> 
#include<string> 
#include<algorithm> 
using namespace std; 

// Array sizes bumped to 5005 to safely hold up to 5000 digits
int a[5005], b[5005], c[5020]; 

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
    cout << "\n";
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

void copy_arr(int src[], int dest[]) {
    for(int i = 0; i <= src[0]; i++) {
        dest[i] = src[i];
    }
}

bool check_prefix(int arr[], string sa) {
    int len = sa.size();
    if (arr[0] < len) return false;
    
    for(int i = 0; i < len; i++) {
        if (arr[arr[0] - i] != (sa[i] - '0')) {
            return false;
        }
    }
    return true;
}

string sa, sb;

int main() {
    cin >> sa;
    a[0] = 1;
    a[1] = 1;
    while(true) {
        if (check_prefix(a, sa)) 
        {
            print(a);
            break;
        }
        mult(a, 2, b);
        copy_arr(b, a);
    }
    return 0; 
}
