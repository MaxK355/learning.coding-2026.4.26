#include<cstdio>
using namespace std;

int fib(int k)
{
    if(k == 2 || k == 1)
    {
        return 1;
    }
    return fib(k - 1) + fib(k - 2);
}

int main()
{
	int k;
	scanf("%d", &k);
	printf("%d\n", fib(k));
    return 0;
}
