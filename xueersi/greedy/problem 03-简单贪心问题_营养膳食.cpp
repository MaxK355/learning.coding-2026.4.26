#include <iostream>
#include <algorithm>
using namespace std;

struct node{
    int a,b;
}  food[205];

bool cmp(node x, node y)
{
    return x.a > y.a;
}

int main(){
  	int n, m, k, ans =0, cnt[105];
  	cin >> n>> m >>k;
  	for(int i=1;i<=k;i++)
  	{
  	    cin >> cnt[i];
  	}
  	for(int i=1;i<=n;i++)
  	{
  	    cin >> food[i].a >> food[i].b;
  	}
  	
  	sort(food+1,food+n+1,cmp);
  	for(int i=1;i<=n;i++)
  	{
  	    int a=food[i].a;
  	    int b=food[i].b;
  	    if(m > 0 && cnt[b] >0)
  	    {
  	        m--;
  	        cnt[b]--;
  	        ans += a;
  	    }
  	}
  	cout << ans;
    return 0;
}