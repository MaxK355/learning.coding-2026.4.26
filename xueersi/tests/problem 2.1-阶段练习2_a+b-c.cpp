#include <iostream>
using namespace std;
//将字符串s转化存储到高精度数组a中
void s2BIG(string s, int a[])
{
    a[0]=s.size();
    for(int i=1; i<=a[0]; i++)
        a[i]=s[a[0]-i]-'0';  //逆序存储
}
//输出高精度数字a
void printBIG(int a[])
{
    for(int i=a[0]; i>=1; i--)
        cout << a[i];
    cout << endl;
}
//将高精度数字a和高精度数字b的和存入高精度数组c
void addBIG(int a[], int b[], int c[])
{
    c[0]=max(a[0], b[0]);//按照位数多的计算
    int u=0;//进位
    for(int i=1; i<=c[0]; i++)
    {
        int t=a[i]+b[i]+u;//模拟加法
        c[i]=t%10;//当前位
        u=t/10;
    }
    if(u>0) c[++c[0]]=u;
}
//比较高精度数字a和高精度数字b的大小：a是否小于b
bool cmpBIG(int a[], int b[])
{ 
	if(a[0] != b[0]) return a[0] < b[0];
	for(int i = a[0]; i >= 1; i--)
		if(a[i] != b[i]) return a[i] < b[i];
	return false;
}
//计算高精度数字a和高精度数字b的差存入高精度数组c
void subBIG(int a[], int b[], int c[])
{ 
	c[0] = max(a[0], b[0]);
	int u = 0; //u表示低位向高位的借位
	for(int i = 1; i <= c[0]; i++)
	{
		int t = a[i] - b[i] - u;
		if(t < 0)
		{
			c[i] = t + 10;
			u = 1;
		}
		else
		{
			c[i] = t;
			u = 0;
		}
	}
	while(c[c[0]] == 0 && c[0] > 1) c[0]--;
}
int a[1005], b[1005], c[1005],ans1[1005],ans2[1005];
string a1,b1,c1;
int main()
{
    cin >> a1 >> b1 >> c1;
    s2BIG(a1,a);
    s2BIG(b1,b);
    s2BIG(c1,c);
    addBIG(a,b,ans1);
    if(cmpBIG(ans1,c) == true)
    {
        subBIG(c,ans1,ans2);
        cout << '-';
        printBIG(ans2);
    }
    else
    {
        subBIG(ans1,c,ans2);
        printBIG(ans2);
    }
    return 0;
}