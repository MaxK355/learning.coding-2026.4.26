#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int n, t;
double ans = 0;

struct coin{
    int m, v;
    double unit;
}a[105];

bool cmp(coin x,coin y)
{
    return x.unit > y.unit;
}

int main(){
  	cin >> n >> t;
  	for(int i = 0;i < n;i++)
  	{
  	    cin >> a[i].m >> a[i].v;
  	    a[i].unit = (double)a[i].v / a[i].m;
  	}
  	sort(a,a+n,cmp);
  	for(int i = 0;i < n;i++)
  	{
  	    if(t >= a[i].m)
  	    {
  	        t -= a[i].m;
  	        ans += a[i].v;
  	    }
  	    else
  	    {
  	        ans += (double)a[i].unit * t;
  	        break;
  	    }
  	}
  	printf("%.2lf", ans);
    return 0;
}