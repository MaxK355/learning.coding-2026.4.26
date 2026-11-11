#include<cstdio>
using namespace std;

//在此定义函数
int cmb(int n,int m)
{
    if(n == m || m == 0)
    {
        return 1;
    }
    return cmb(n-1,m) + cmb(n-1,m-1);
}

int main() 
{
	int n, m;
	scanf("%d%d", &n, &m);
	printf("%d\n", cmb(n, m));
    return 0;
}
