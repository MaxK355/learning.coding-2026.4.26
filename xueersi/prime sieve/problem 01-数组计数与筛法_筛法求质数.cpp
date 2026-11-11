#include <iostream>
#include <cstring>
using namespace std;

int n, m;
bool f[10000005];

void primes(int n){
    memset(f, 1, n);
    f[0] = 0;
    f[1] = 0;
    for(int i = 2;i * i <= n;i++)
    {
        if(f[i] == true)
        {
            for(int j = i * i;j <= n;j += i)
            {
                f[j] = 0;
            }
        }
    }
}

int main(){
	cin >> n >> m;
	primes(n);
	while(m > 0)
	{
	    m--;
	    int x;
	    cin >> x;
	    if(f[x] == true)
	    {
	        cout << "Yes" << endl;
	    }
	    else
	    {
	        cout << "No" << endl;
	    }
	}
	return 0;
}